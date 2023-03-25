#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>

void Task_1 (void* ags1){
    while (1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        ESP_LOGI("TASK1", "Read sample");
    }
}

void Task_2 (void* arg2){
    int* args_ptr = (int*) arg2;
    ESP_LOGI("TASK2", "Received argument %d\n", args_ptr[0]);

    while (1){
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        ESP_LOGI("TASK2", "Calculate mean");
    }
    
}

void app_main(void) {
    xTaskCreatePinnedToCore(&Task_1,
                            "TASK_1_",
                            4096,
                            NULL,
                            0,
                            NULL,
                            0); // pin to specialize cores

    // must be "static" for passing as argument
    static int number = 42;
    xTaskCreate(&Task_2,
                "TASK_2_",
                4096,
                (void*) &number,
                1,
                NULL);

}