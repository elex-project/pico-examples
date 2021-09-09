#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

int main()
{
    bi_decl(bi_program_description("Hello Serial via USB."));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        gpio_put(LED_PIN, false);
        sleep_ms(250);
        gpio_put(LED_PIN, true);
        puts("Hello World~~!");
        sleep_ms(1000);
    }
}