# Using mutex

## Create mutex as global var
docs: https://www.freertos.org/a00113.html

    SemaphoreHandle_t xSemaphore;

    void vATask( void * pvParameters )
    {
    /* Create a mutex type semaphore. */
    xSemaphore = xSemaphoreCreateMutex();

    if( xSemaphore != NULL )
    {
        /* The semaphore was created successfully and
        can be used. */
    }
    }

## Critical region and lock usage

docs: https://www.freertos.org/a00122.html

    SemaphoreHandle_t xSemaphore = NULL;

    void vATask( void * pvParameters )
    {
        xSemaphore = xSemaphoreCreateMutex();
    }

    void vAnotherTask( void * pvParameters )
    {
        if( xSemaphore != NULL )
        {
            /* See if we can obtain the semaphore.  If the semaphore is not
            available wait 10 ticks to see if it becomes free. */
            if( xSemaphoreTake( xSemaphore, ( TickType_t ) 10 ) == pdTRUE )
            {
                /* ... */

                /* We have finished accessing the shared resource.  Release the
                semaphore. */
                xSemaphoreGive( xSemaphore );
            }
            else
            {
                /* We could not obtain the semaphore and can therefore not access
                the shared resource safely. */
            }
        }
    }
