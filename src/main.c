#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <stdlib.h>
#include <time.h>
#include "dvp_camera.h"
#include "lcd.h"
#include "../include/shared.h"
#include "sm3.h"
#include "sm4.h"
#include "gmssl_cfg.h"

SemaphoreHandle_t semAvailable, semEmpty;
uint8_t *Encrypted_data;
// Encryption and Verify
uint8_t myKey[16] = "This is my key\r\n";

void TaskDataEncrypt()
{
    uint8_t iv[16];
    size_t encrypt_len, encrypt_len_finish;
    while (1)
    {
        xSemaphoreTake(semAvailable, portMAX_DELAY);
        
        lcd_draw_picture(0, 0, 320, 240, lcd_gram0);    // display the photo

        // Do - Encryption & MAC
        
        // initialize iv
        for (int *iv_p = (int *)iv; iv_p < (iv + 16); iv_p++)
            *iv_p = rand();
        // for (int i = 0; i < 16; i++)
        //     printf("%hhx ", iv[i]);
        // putchar('\n');

        // do encryption
        SM4_CBC_CTX myctx;
        sm4_cbc_encrypt_init(&myctx, myKey, iv);
        sm4_cbc_encrypt_update(&myctx, (uint8_t *)lcd_gram0, GRAM_SIZE, Encrypted_data, &encrypt_len);
        sm4_cbc_encrypt_finish(&myctx, Encrypted_data + encrypt_len, &encrypt_len_finish);
        encrypt_len += encrypt_len_finish;  // sum up the enc len
        // sm4_cbc_padding_encrypt(&myKey, iv, (uint8_t *)lcd_gram0, GRAM_SIZE, Encrypted_data, &encrypt_len);

        printf("encrypt_len: %lu\n", encrypt_len);
        // for (int i = 0; i < 32; i++)
        //     printf("%02hhx ", Encrypted_data[i]);
        for (int *enc_p = (int *)Encrypted_data; enc_p < &Encrypted_data[encrypt_len >> 8]; enc_p++)
            printf("%08x ", *enc_p);
        // do sm3-mac
        sm3_digest(Encrypted_data, encrypt_len, &Encrypted_data[encrypt_len]);

        puts("\nMAC data:");
        for (int i = 0; i < SM3_DIGEST_SIZE; i++)
            printf("%02hhx ", Encrypted_data[encrypt_len + i]);
        putchar('\n');
        // for (int i = 0; i < sizeof(Encrypted_data); i++)
        //     printf("%hhx", Encrypted_data[i]);
        

        xSemaphoreGive(semEmpty);
    }
    vTaskDelete(NULL);
}

// test Data Generator. When released, data is from Camera
void TaskGenerator()
{
    while (1)
    {
        xSemaphoreTake(semEmpty, portMAX_DELAY);
        // fill data
        for (int i = 0; i < DVP_HIGHT * DVP_WIDTH / 2; i++)
            lcd_gram0[i] = rand();
        xSemaphoreGive(semAvailable);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}

int main(void)
{
    // initialize Semaphores
    semAvailable = xSemaphoreCreateBinary();
    semEmpty = xSemaphoreCreateBinary();
    xSemaphoreGive(semEmpty);   // initialize Binary Semaphore to 1

    // initialize Key
    srand((unsigned long)clock());
    sm4_set_encrypt_key(&myKey, KEY_RAW);


    Encrypted_data = (uint8_t *)malloc(GRAM_SIZE + SM4_BLOCK_SIZE * 2 + SM3_DIGEST_SIZE);

    printf("lcd init\n");
    lcd_init();
    printf("DVP init\n");
    dvp_init();

    printf("Main is running on %d\n", (int)uxPortGetProcessorId());
    xTaskCreateAtProcessor(1, TaskDataEncrypt, "DataEncrypt", 1024, NULL, 3, NULL);
    xTaskCreateAtProcessor(0, TaskGenerator, "DataGenerator", 1024, NULL, 3, NULL);
    vTaskDelete(NULL);
}
