#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <stdlib.h>
#include "dvp_camera.h"
#include "lcd.h"
#include "../include/shared.h"
#include "sm3.h"
#include "sm4.h"

SemaphoreHandle_t semAvailable, semEmpty;
uint8_t *Encrypted_data;

void TaskDataEncrypt()
{
    while (1)
    {
        xSemaphoreTake(semAvailable, portMAX_DELAY);
        
        lcd_draw_picture(0, 0, 320, 240, lcd_gram0);    // display the photo

        // Do - Encryption & MAC

        for (int i = 0; i < sizeof(Encrypted_data); i++)
            printf("%hhx", Encrypted_data[i]);

        xSemaphoreGive(semEmpty);
    }
    vTaskDelete(NULL);
}

// To do: Create a test data generator

int main(void)
{
    // initialize Semaphores
    semAvailable = xSemaphoreCreateBinary();
    semEmpty = xSemaphoreCreateBinary();
    xSemaphoreGive(semEmpty);   // initialize Binary Semaphore to 1

    Encrypted_data = (uint8_t *)malloc(GRAM_SIZE + SM4_BLOCK_SIZE * 2 + SM3_DIGEST_SIZE);
    
    printf("lcd init\n");
    lcd_init();
    printf("DVP init\n");
    dvp_init();

    printf("Main is running on %d\n", (int)uxPortGetProcessorId());
    xTaskCreateAtProcessor(0, TaskDataEncrypt, "DataEncrypt", 1024, NULL, 3, NULL);
    vTaskDelete(NULL);
}
