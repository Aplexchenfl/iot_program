#include "../include/gpio_led.h"

void gpio_led_init(struct iot_gpio *gpio_led, int io_count, int *gpio_num, int sleep_one_run, int sleep_all_run)
{
    int i ;
    char command_export[128], command_out[128];

    gpio_led->io_count = io_count;
    gpio_led->sleep_one_run = sleep_one_run;
    gpio_led->sleep_all_run = sleep_all_run;

    for (i = 0; i < gpio_led->io_count; i++)
    {
        gpio_led->io_num[i] = gpio_num[i];
    }

    for (i = 0; i < gpio_led->io_count; i++)
    {
        sprintf(command_export, "echo %d > /sys/class/gpio/export", gpio_led->io_num[i]);
        system(command_export);

        sprintf(command_out, "echo out > /sys/class/gpio%d/direction", gpio_led->io_num[i]);
        system(command_out);
    }
}

void gpio_led_control(int gpio_num, int gpio_out)
{
    char command[128];

    sprintf(command, "echo %d > /sys/class/gpio%d/direction", gpio_out, gpio_num);
    system(command);
}

void gpio_led_on(int gpio_num)
{
    gpio_led_control(gpio_num, 1);
}

void gpio_led_off(int gpio_num)
{
    gpio_led_control(gpio_num, 0);
}

void gpio_led_exit(struct iot_gpio *gpio_led)
{
    int i ;
    char command_unexport[128];
    for (i = 0; i < gpio_led->io_count; i++)
    {
        sprintf(command_unexport, "echo %d > /sys/class/gpio/unexport", gpio_led->io_num[i]);
        system(command_unexport);
    }
}

void gpio_led_run(struct iot_gpio *gpio_led)
{
    int i;

    for (i = 0; i < gpio_led->io_count; i++)
    {
        if (!i)
            gpio_led_on(gpio_led->io_num[i]);
        else if(i == (gpio_led->io_count - 1))
            gpio_led_off(gpio_led->io_num[i]);
        else
        {
            gpio_led_on(gpio_led->io_num[i]);
            gpio_led_off(gpio_led->io_num[ i - 1 ]);
        }
        usleep(gpio_led->sleep_one_run);
    }

    for (i = 0; i < gpio_led->io_count; i++)
    {
        gpio_led_on(gpio_led->io_num[i]);
    }

    usleep(gpio_led->sleep_all_run);

    for (i = 0; i < gpio_led->io_count; i++)
    {
        gpio_led_off(gpio_led->io_num[i]);
    }
}


