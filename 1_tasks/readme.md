# Tasks (Threads) in FreeRTOS

Usage of tasks and concurrency

## Create task
    BaseType_t xTaskCreate(    TaskFunction_t pvTaskCode,               // pointer to function
                                const char * const pcName,              // debug name
                                configSTACK_DEPTH_TYPE usStackDepth,    // stack for task (words)
                                void *pvParameters,                     // arguments
                                UBaseType_t uxPriority,                 // 0=highest
                                TaskHandle_t *pxCreatedTask
                            );

docs: https://www.freertos.org/a00125.html

## Passing arguments
MUST be of type 'static' or 'global'

## Pin to core
    BaseType_t xTaskCreatePinnedToCore(    TaskFunction_t pvTaskCode,     //function ptr
                                            const char * const pcName,    // debug name
                                            usStackDepth,    // stack for task (words)
                                            void *pvParameters,           // arguments
                                            UBaseType_t uxPriority,       // 0=highest
                                            TaskHandle_t *pxCreatedTask,
                                            const BaseType_t xCoreID      // core number (0,1)
                                        );