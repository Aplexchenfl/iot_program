#include "../include/buzzer_detect.h"

int main(void)
{
    struct buzzer_detect *buzzer_pwm;

    buzzer_pwm = buzzer_detect_init();

    buzzer_pwm->enable(buzzer_pwm);

    buzzer_pwm->write_period(buzzer_pwm, 0);

    buzzer_pwm->write_duty_cycle(buzzer_pwm, 0);

    sleep(3);

    buzzer_pwm->disable(buzzer_pwm);

    buzzer_pwm->release(buzzer_pwm);

    return 0;
}
