#include "../include/gpio_led.h"

struct iot_gpio *gpio_led_create(int io_count, int *gpio_num, int sleep_one_run, int sleep_all_run)
{
    struct iot_gpio *gpio_led;
    int i;

    gpio_led = malloc(sizeof(struct iot_gpio));
    if (gpio_led == NULL)
        return NULL;

    memset (gpio_led, 0, sizeof(struct iot_gpio));

    gpio_led->io_count = io_count;
    gpio_led->sleep_one_run = sleep_one_run;
    gpio_led->sleep_all_run = sleep_all_run;

    for (i = 0; i < gpio_led->io_count; i++)
    {
        gpio_led->io_num[i] = gpio_num[i];
    }

    gpio_led->init = gpio_led_init;
    gpio_led->control = gpio_led_control;
    gpio_led->run = gpio_led_run;
    gpio_led->on = gpio_led_on;
    gpio_led->off = gpio_led_off;
    gpio_led->exit = gpio_led_exit;

    return gpio_led;
}

void gpio_led_init(struct iot_gpio *gpio_led)
{
    int i;
    char command_export[128], command_out[128];


    for (i = 0; i < gpio_led->io_count; i++)
    {
        sprintf(command_export, "echo %d > /sys/class/gpio/export", gpio_led->io_num[i]);
        system(command_export);

        sprintf(command_out, "echo out > /sys/class/gpio/gpio%d/direction", gpio_led->io_num[i]);
        system(command_out);
    }

}

void gpio_led_control(int gpio_num, int gpio_out)
{
    char command[128];

    sprintf(command, "echo %d > /sys/class/gpio/gpio%d/value", gpio_out, gpio_num);
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
        if (i == 0)
            gpio_led_on(gpio_led->io_num[i]);
        else
        {
            gpio_led_on(gpio_led->io_num[i]);
            gpio_led_off(gpio_led->io_num[ i - 1 ]);
        }
        usleep(gpio_led->sleep_one_run);
    }
    gpio_led_off(gpio_led->io_num[i - 1]);
    usleep(gpio_led->sleep_one_run);

    for (i = (gpio_led->io_count - 1); i >= 0; i--)
    {
        if (i == (gpio_led->io_count - 1))
            gpio_led_on(gpio_led->io_num[i]);
        else
        {
            gpio_led_on(gpio_led->io_num[i]);
            gpio_led_off(gpio_led->io_num[ i + 1 ]);
        }
        usleep(gpio_led->sleep_one_run);
    }
    gpio_led_off(gpio_led->io_num[i + 1]);
    usleep(gpio_led->sleep_one_run);

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


