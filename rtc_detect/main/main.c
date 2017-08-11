#include "../include/rtc_detect.h"

int main(void)
{
    unsigned int count_time = read_rtc_time();

    printf("%ld\n", count_time);

    return 0;
}
