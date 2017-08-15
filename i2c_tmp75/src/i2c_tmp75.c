#include "../include/i2c_tmp75.h"

struct i2c_tmp75 *tmp75_init(int slave_register, char *i2c_dev, char *tmp75_output_dev)
{
    struct i2c_tmp75 *tmp75;

    tmp75 = (struct i2c_tmp75 *)malloc(sizeof(struct i2c_tmp75));
    if (!tmp75)
        return NULL;

    memset(tmp75, 0, sizeof(struct i2c_tmp75));

    tmp75->temperature = 0;
    tmp75->slave_register = slave_register;
    strcpy(tmp75->i2c_dev, i2c_dev);
    strcpy(tmp75->tmp75_output_dev, tmp75_output_dev);

    tmp75->init = tmp75_init;
    tmp75->read = tmp75_read;
    tmp75->exit = tmp75_exit;

    return tmp75;
}

float tmp75_read(struct i2c_tmp75 *tmp75)
{
    int fd, i, n = 1;
    char tmp[5];

    fd = open(tmp75->tmp75_output_dev, O_RDONLY);
    if (fd < 0)
    {
        perror("open device error");
        return -1;
    }

    read(fd, tmp, 5);

    for (i = 4; i >=0; i--)
    {
        tmp75->temperature += ((float )(tmp[i] - '0')) / 1000 * n;
        n *= 10;
    }

    //tmp75->temperature = ((float )tmp[4] - 48) / 1000 + ((float )tmp[3] - 48) / 100 +
    //    ((float )tmp[2] - 48) / 10 + ((float )tmp[1] - 48) + ((float )tmp[0] - 48) * 10 ;

    close(fd);

    return tmp75->temperature;
}

void tmp75_exit(struct i2c_tmp75 *tmp75)
{
    free(tmp75);
}

