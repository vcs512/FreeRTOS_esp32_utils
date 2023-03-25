#include "../include/read_sensor.h"
#include "../include/write_lcd.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

#include <esp_log.h>

int sample;
SemaphoreHandle_t mutex_bus;

void read_task (void* address){
    while (1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
        if (xSemaphoreTake(mutex_bus, 5 / portTICK_PERIOD_MS)){
            sample = read_sensor( (unsigned int*) address);

            xSemaphoreGive(mutex_bus);
        }
        else{
            ESP_LOGE("read sensor", "missed a sample!");
        }
        
    }
}

void write_task (void* address){
    while (1){
        vTaskDelay(4000 / portTICK_PERIOD_MS);

        if (xSemaphoreTake(mutex_bus, portMAX_DELAY)){
            write_LCD( (unsigned int*) address, sample);

            xSemaphoreGive(mutex_bus);
        }
        
    }
}


void app_main(void) {
    
mutex_bus = xSemaphoreCreateMutex();

// read
static unsigned int* sensor_address = 0x48;
xTaskCreate(&read_task,
            "read TASK",
            2048,
            (void*) sensor_address,
            0,
            NULL
            );

// write
static unsigned int* lcd_address = 0x64;
xTaskCreate(&write_task,
            "write TASK",
            2048,
            (void*) lcd_address,
            10,
            NULL
            );
}