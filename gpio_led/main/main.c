#include "../include/gpio_led.h"

int main(void)
{
    struct iot_gpio *gpio_led;

    gpio_led = gpio_led_init();

    gpio_led->run(gpio_led);
    gpio_led->exit(gpio_led);

    return 0;
}
