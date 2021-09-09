#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

int main()
{
    bi_decl(bi_program_description("Blink"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        gpio_put(LED_PIN, true);
        sleep_ms(750);
        gpio_put(LED_PIN, false);
        sleep_ms(250);
        gpio_put(LED_PIN, true);
        sleep_ms(250);
        gpio_put(LED_PIN, false);
        sleep_ms(250);
    }
}