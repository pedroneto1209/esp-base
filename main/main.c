/*
 Remember to change base_project name and README
 Remember to configure project board: Flash size, CPU speed etc.

 /build:
 - bootloader.bin: Bootloader binary file to load in the MCU.
 - partition-table.bin: Firmware partitions addresses to load in the MCU.
 - study.bin: Main project binary file to load in the MCU.
 - study.elf: Used for debugging the firmware (with JTAG).
*/

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN GPIO_NUM_2

void app_main(void) {

    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}