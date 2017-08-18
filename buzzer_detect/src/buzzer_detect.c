#include "../include/buzzer_detect.h"

struct buzzer_detect *buzzer_detect_init(void)
{
    struct buzzer_detect *buzzer_pwm;
    char command_buf[PWM_BUFF_SIZE];

    buzzer_pwm = (struct buzzer_detect *)malloc(sizeof(struct buzzer_detect));
    if (buzzer_pwm == NULL)
        return NULL;

    bzero(buzzer_pwm, sizeof(struct buzzer_detect));

    strcpy(buzzer_pwm->pwm_device_export, PWM_DEVICE_EXPORT);
    strcpy(buzzer_pwm->pwm_device_unexport, PWM_DEVICE_UNEXPORT);
    strcpy(buzzer_pwm->pwm_device_pwm0_enable, PWM_DEVICE_PWM0_ENABLE);
    strcpy(buzzer_pwm->pwm_device_pwm0_period, PWM_DEVICE_PWM0_PERIOD);
    strcpy(buzzer_pwm->pwm_device_pwm0_duty_cycle, PWM_DEVICE_PWM0_DUTY_CYCLE);

    buzzer_pwm->enable = buzzer_detect_enable;
    buzzer_pwm->disable = buzzer_detect_disable;
    buzzer_pwm->write_period = buzzer_detect_write_period;
    buzzer_pwm->write_duty_cycle = buzzer_detect_write_duty_cycle;
    buzzer_pwm->release = buzzer_detect_release;

    sprintf(command_buf, "echo %d >  %s", 0, buzzer_pwm->pwm_device_export);
    system(command_buf);

    return buzzer_pwm;
}

static int run_command(char *device_name, int run_num)
{
    char command_buf[PWM_BUFF_SIZE];

    sprintf(command_buf, "echo %d > %s ", run_num, device_name);
    return system(command_buf);
}

static int buzzer_detect_able(struct buzzer_detect *buzzer_pwm, int able)
{
    return run_command(buzzer_pwm->pwm_device_pwm0_enable, able);
}

int buzzer_detect_enable(struct buzzer_detect *buzzer_pwm)
{
    return buzzer_detect_able(buzzer_pwm, 1);
}

int buzzer_detect_disable(struct buzzer_detect *buzzer_pwm)
{
    return buzzer_detect_able(buzzer_pwm, 0);
}

int buzzer_detect_write_period(struct buzzer_detect *buzzer_pwm, int period)
{
    if (period == 0)
        return run_command(buzzer_pwm->pwm_device_pwm0_period, PWM_PERIOD);
    else
        return run_command(buzzer_pwm->pwm_device_pwm0_period, period);
}

int buzzer_detect_write_duty_cycle(struct buzzer_detect *buzzer_pwm, int duty_cycle)
{
    if (duty_cycle == 0)
        return run_command(buzzer_pwm->pwm_device_pwm0_duty_cycle, PWM_DUTY_CYCLE);
    else
        return run_command(buzzer_pwm->pwm_device_pwm0_duty_cycle, duty_cycle);
}

void buzzer_detect_release(struct buzzer_detect *buzzer_pwm)
{
    run_command(buzzer_pwm->pwm_device_unexport, 0);

    free(buzzer_pwm);
}

