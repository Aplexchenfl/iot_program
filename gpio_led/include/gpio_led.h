#ifndef __GPIO_LED_H__
#define __GPIO_LED_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * structure iot_gpio
 * io_count : gpio count num.
 * io_num   : gpio number array.
 * sleep_one_run : A led run sleep time (us).
 * sleep_all_run : All led run sleep time (us).
 *
 * init : init gpio
 * control : set gpio(n) to 1 or 0
 * on : set gpio(n) to 1
 * off : set gpio(n) to 0
 * exit : gpio unexport function
 * run : run all gpio led
 */

#define IO_COUNT_NUMBER  8

struct iot_gpio
{
    int io_count;
    int io_num[IO_COUNT_NUMBER];
    int sleep_one_run;
    int sleep_all_run;
    struct iot_gpio *(* init)(void);
    void (* control)(int gpio_num, int gpio_out);
    void (* on)(int gpio_num);
    void (* off)(int gpio_num);
    void (* exit)(struct iot_gpio *);
    void (* run)(struct iot_gpio *);
    void (* run_lefttoright)(struct iot_gpio *);
    void (* run_righttoleft)(struct iot_gpio *);
    void (* run_all)(struct iot_gpio *);
    void (* stop_all)(struct iot_gpio *);
};

/*   gpio_led_init : create and init An iot_gpio structure   */
struct iot_gpio *gpio_led_init(void);

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

void gpio_led_run_lefttoright(struct iot_gpio *gpio_led);
void gpio_led_run_righttoleft(struct iot_gpio *gpio_led);
void gpio_led_run_all(struct iot_gpio *gpio_led);
void gpio_led_stop_all(struct iot_gpio *gpio_led);

#endif /* __GPIO_LED_H__ */
