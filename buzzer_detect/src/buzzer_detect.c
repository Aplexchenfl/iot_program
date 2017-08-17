#include "../include/buzzer_detect.h"


struct buzzer_detect *buzzer_detect_init(void)
{
    struct buzzer_detect *buzzer_pwm;
    int fd;

    buzzer_pwm = (struct buzzer_detect *)malloc(sizeof(struct buzzer_detect));
    if (buzzer_pwm == NULL)
        return NULL;

    bzero(buzzer_pwm, sizeof(struct buzzer_detect));

    strcpy(buzzer_pwm->pwm_device_export, PWM_DEVICE_EXPORT);
    strcpy(buzzer_pwm->pwm_device_unexport, PWM_DEVICE_UNEXPORT);
    strcpy(buzzer_pwm->pwm_device_pwm0_enable, PWM_DEVICE_PWM0_ENABLE);
    strcpy(buzzer_pwm->pwm_device_pwm0_period, PWM_DEVICE_PWM0_PERIOD);
    strcpy(buzzer_pwm->pwm_device_pwm0_duty_cycle, PWM_DEVICE_PWM0_DUTY_CYCLE);

    buzzer_pwm->buzzer_pwm_device_num = PWM_DEVICE_NUM;
    buzzer_pwm->buzzer_pwm_period = PWM_PERIOD;
    buzzer_pwm->buzzer_pwm_duty_cycle = PWM_DUTY_CYCLE;

    fd = open(buzzer_pwm->pwm_device_export, O_RDWR);
    if (fd < 0)
    {
        perror("open device error");
        goto ERR1;
    }

    if ((write(fd, "0", 2)) < 0 )
        goto ERR2;

    close(fd);

    return buzzer_pwm;

ERR2:
    perror("write error");
ERR1:
    free(buzzer_pwm);
}

int buzzer_detect_enable(struct buzzer_detect *buzzer_pwm)
{
    int fd;

    fd = open(buuzer_pwm->pwm_device_pwm0_enable, O_RDWR);
    if (fd < 0)
    {
        perror("open enable device ");
        goto ERR1;
    }

    if (write(fd, "1", 2) < 0)
        goto ERR2;

    close(fd);
    return 0;

ERR2:
    perror("write error");
    close(fd);
ERR1:
    return -1;
}

int buzeer_detect_write_period(struct buzzer_detect *buzzer_pwm, int period)
{

}

int buzzer_detect_write_duty_cycle(struct buzzer_detect *buzzer_pwm, int duty_cycle)
{

}

int buzzer_detect_control(struct buzzer_detect *buzzer_pwm)
{

}

int buzzer_detect_disable(struct buzzer_detect *buzzer_pwm)
{

}

void buzzer_detect_release(struct buzzer_detect *buzzer_pwm)
{
    free(buzzer_pwm);
}

