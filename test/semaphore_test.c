#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "dvp_camera.h"
#include "lcd.h"
#include <semphr.h>
#include "../include/shared.h"

SemaphoreHandle_t semAvailable, semEmpty;

void TaskDataEncrypt()
{
    printf("Task Created 1\n");
    while (1)
    {
        if (xSemaphoreTake(semEmpty, 100000 / portTICK_PERIOD_MS) == pdTRUE)
            printf("semEmpty Taken by 1\n");
        // xSemaphoreCreateMutex
        vTaskDelay(1500 / portTICK_PERIOD_MS);
        
        // dvp_finish_flag = 0;
        // lcd_draw_picture(0, 0, 320, 240, gram_mux ? lcd_gram1 : lcd_gram0);
        // gram_mux ^= 0x01;
        printf("Test ID %d\n", (int)uxPortGetProcessorId());
        if (xSemaphoreGive(semAvailable) == pdTRUE)
            printf("semAvailable Given by 1\n");
    }
    vTaskDelete(NULL);
}

void TaskDataEncrypt2()
{
    printf("Task Created 2\n");
    // xSemaphoreTake(semEmpty, portMAX_DELAY);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);  // wait for init of 1
    while (1)
    {
        if (xSemaphoreTake(semAvailable, 100000 / portTICK_PERIOD_MS) == pdTRUE)
            printf("semAvailable Taken by 2\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        
        // dvp_finish_flag = 0;
        // lcd_draw_picture(0, 0, 320, 240, gram_mux ? lcd_gram1 : lcd_gram0);
        // gram_mux ^= 0x01;
        printf("Test ID %d\n", (int)uxPortGetProcessorId());
        if (xSemaphoreGive(semEmpty) == pdTRUE)
            printf("semEmpty given by 2\n");
    }
    vTaskDelete(NULL);
}

int main(void)
{
    // initialize Semaphores
    semAvailable = xSemaphoreCreateBinary();
    semEmpty = xSemaphoreCreateBinary();
    xSemaphoreGive(semEmpty);
    // if (semAvailable == NULL)
    //     printf("Error Creating Semaphore\n");
    printf("lcd init\n");
    lcd_init();
    printf("DVP init\n");
    dvp_init();

    printf("Main is running on %d\n", (int)uxPortGetProcessorId());
    xTaskCreateAtProcessor(0, TaskDataEncrypt, "DataEncrypt", 1024, NULL, 3, NULL);
    xTaskCreateAtProcessor(1, TaskDataEncrypt2, "HelloWorld", 1024, NULL, 3, NULL);
    vTaskDelete(NULL);
}
