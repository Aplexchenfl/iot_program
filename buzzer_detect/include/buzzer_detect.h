#ifndef __BUZZER_DETECT_H__
#define __BUZZER_DETECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PWM_DEVICE_EXPORT               "/sys/class/pwm/pwmchip1/export"
#define PWM_DEVICE_UNEXPORT             "/sys/class/pwm/pwmchip1/unexport"
#define PWM_DEVICE_PWM0_ENABLE          "/sys/class/pwm/pwmchip1/pwm0/enable"
#define PWM_DEVICE_PWM0_PERIOD          "/sys/class/pwm/pwmchip1/pwm0/period"
#define PWM_DEVICE_PWM0_DUTY_CYCLE      "/sys/class/pwm/pwmchip1/pwm0/duty_cycle"
#define FILE_NAME_SIZE  64
#define PWM_DEVICE_NUM 0
#define PWM_PERIOD 200000
#define PWM_DUTY_CYCLE 100000

struct buzzer_detect
{
    char pwm_device_export[FILE_NAME_SIZE];
    char pwm_device_unexport[FILE_NAME_SIZE];
    char pwm_device_pwm0_enable[FILE_NAME_SIZE];
    char pwm_device_pwm0_period[FILE_NAME_SIZE];
    char pwm_device_pwm0_duty_cycle[FILE_NAME_SIZE];

    int buzzer_pwm_device_num;
    int buzzer_pwm_period;
    int buzzer_pwm_duty_cycle;

    int (* control)(struct buzzer_detect *buzzer_pwm);
    void (* exit)(struct buzzer_detect *buzzer_pwm);
};

struct buzzer_detect *buzzer_detect_init(void);
int buzzer_detect_enable(struct buzzer_detect *buzzer_pwm);
int buzeer_detect_write_period(struct buzzer_detect *buzzer_pwm, int period);
int buzzer_detect_write_duty_cycle(struct buzzer_detect *buzzer_pwm, int duty_cycle);
int buzzer_detect_control(struct buzzer_detect *buzzer_pwm);
int buzzer_detect_disable(struct buzzer_detect *buzzer_pwm);
void buzzer_detect_release(struct buzzer_detect *buzzer_pwm);

#endif
