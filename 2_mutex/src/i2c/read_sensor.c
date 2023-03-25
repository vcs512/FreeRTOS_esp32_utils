#include "../../include/read_sensor.h"

#include <esp_log.h>
#include <stdlib.h>

 int read_sensor(unsigned int* address){
    int sample = rand() % 10;
    ESP_LOGI("read_sensor", "sampled value %d in address %p", sample, address);
    
    return sample;
}