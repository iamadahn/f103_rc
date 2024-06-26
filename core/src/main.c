#include "main.h"
#include "bsp.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "rtos.h"

int
main(void) {
    bsp_init();
    threads_init();
    queues_init();

    vTaskStartScheduler();

    /* should never reach here */
    while (1) {
        ;
    }

    return 0;
}
