#include "display_controller.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "stdio.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "fonts.h"
#include "stm32f1xx_ll_i2c.h"

void
display_controller_handler(void) {
    
    uint8_t tx_buf[64];
    sprintf(tx_buf, "BUBLIK");

    ssd1306_t ssd1306 = {
        .i2c_base = I2C1,
        .address = SSD1306_I2C_ADDR,
    };

    ssd1306_Init(&ssd1306);

    ssd1306_Fill(&ssd1306, Black);
    ssd1306_UpdateScreen(&ssd1306);

    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_6x8, White);

    ssd1306_SetCursor(&ssd1306, 10, 10);
    sprintf(tx_buf, "PRODUCTIONS");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_6x8, White);
    ssd1306_UpdateScreen(&ssd1306);

    ssd1306_SetCursor(&ssd1306, 20, 20);
    sprintf(tx_buf, "ENCORPORATED");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_6x8, White);
    ssd1306_UpdateScreen(&ssd1306);

    ssd1306_SetCursor(&ssd1306, 30, 30);
    sprintf(tx_buf, "PRESENTS...");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_6x8, White);
    ssd1306_UpdateScreen(&ssd1306);

    vTaskDelay(pdMS_TO_TICKS(5000));

    ssd1306_Fill(&ssd1306, Black);
    ssd1306_UpdateScreen(&ssd1306);

    ssd1306_SetCursor(&ssd1306, 0, 0);
    sprintf(tx_buf, "THE");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_11x18, White);
    ssd1306_UpdateScreen(&ssd1306);
    vTaskDelay(pdMS_TO_TICKS(500));

    ssd1306_SetCursor(&ssd1306, 0, 20);
    sprintf(tx_buf, "RC");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_11x18, White);
    ssd1306_UpdateScreen(&ssd1306);
    vTaskDelay(pdMS_TO_TICKS(500));

    ssd1306_SetCursor(&ssd1306, 0, 40);
    sprintf(tx_buf, "CAR");
    ssd1306_WriteString(&ssd1306, (char*)tx_buf, Font_11x18, White);
    ssd1306_UpdateScreen(&ssd1306);
    vTaskDelay(pdMS_TO_TICKS(500));

    while (1) {
        ;
    }
}