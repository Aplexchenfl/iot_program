#include "../include/i2c_tmp75.h"


float read_tmp(void)
{
    int tmp_fd;
    char tmp[5];
    float tmp_val = 0;

    tmp_fd = open("/sys/bus/i2c/devices/2-004c/hwmon/hwmon0/temp1_input", O_RDONLY);
    if (tmp_fd < 0)
    {
        perror(" open tmp errno ");
        return -1;
    }

    read(tmp_fd, tmp, 5);

    tmp_val = ((float )tmp[4] - 48) / 1000 + ((float )tmp[3] - 48) / 100 + ((float )tmp[2] - 48) / 10 +
                ((float )tmp[1] - 48) + ((float )tmp[0] - 48) * 10 ;

    close(tmp_fd);

    return tmp_val;
}

