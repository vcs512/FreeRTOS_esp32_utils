// hello world using FreeRTOS in esp32 MCU
#include <stdio.h>
#include <esp_log.h>

void app_main(void) {
    printf("Hello from printf\n");

    // ESP_LOGx (char* TAG. char* message);
    ESP_LOGI( "Info",
              "Hello from LOGI");

    ESP_LOGW( "Warning",
              "Hello from LOGW");

    ESP_LOGE( "Error",
              "Hello from LOGE");

}