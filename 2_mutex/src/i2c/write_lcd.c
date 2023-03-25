#include "../../include/write_lcd.h"

#include <esp_log.h>

void write_LCD(unsigned int* address, int value){
    ESP_LOGI("write_LCD", "writing %d in LCD address %p", value, address);
}