#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void print_data_types()
{
    char c = 23;
    printf("char %d : size=%lu\n", c, sizeof(char)); // 1 byte

    short s = 23;
    printf("short %d : size=%lu\n", s, sizeof(short)); // 2 byte

    int i = 23;
    printf("int %d : size=%lu\n", i, sizeof(int)); // 4 byte

    long l = 23L;
    printf("long %ld : size=%lu\n", l, sizeof(long)); // 4 byte

    long long ll = 23LL;
    printf("long long %lld : size=%lu\n", ll, sizeof(long long)); // 8 byte

    float f = 3.14F;
    printf("float %f : size=%lu\n", f, sizeof(float)); // 4 byte

    double d = 3.14;
    printf("double %f : size=%lu\n", d, sizeof(double)); // 8 byte
}

int main()
{
    bi_decl(bi_program_description("Data types"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        gpio_put(LED_PIN, true);
        print_data_types();
        sleep_ms(250);
        gpio_put(LED_PIN, false);

        sleep_ms(2000);
    }
}