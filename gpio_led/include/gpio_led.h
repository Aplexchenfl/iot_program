#ifndef __GPIO_LED_H__
#define __GPIO_LED_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * structure iot_gpio
 * io_count : gpio count num.
 * io_num   : gpio number array.
 * sleep_one_run : A led run sleep time (us).
 * sleep_all_run : All led run sleep time (us).
 */
struct iot_gpio
{
    int io_count;
    int io_num[8];
    int sleep_one_run;
    int sleep_all_run;
};

/*   gpio_led init : gpio led init function   */
void gpio_led_init(struct iot_gpio *, int io_count, int *, int sleep_one_run, int sleep_all_run);

/*   gpio_led control : set gpio(n) to 1 or 0   */
void gpio_led_control(int gpio_num, int gpio_out);

/*   gpio_led on : set gpio(n) to 1   */
void gpio_led_on(int gpio_num);

/*   gpio_led off : set gpio(n) to 0   */
void gpio_led_off(int gpio_num);

/*   gpio_led exit : gpio unexport function   */
void gpio_led_exit(struct iot_gpio *);

/*   gpio_led run : run all gpio led   */
void gpio_led_run(struct iot_gpio *);

#endif /* __GPIO_LED_H__ */
