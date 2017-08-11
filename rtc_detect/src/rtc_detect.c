#include "../include/rtc_detect.h"

unsigned int read_rtc_time(void)
{
    system("hwclock -s");

    time_t count_time = time(NULL);

    return count_time;
}

