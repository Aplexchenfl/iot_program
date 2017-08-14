#include "../include/i2c_tmp75.h"

int main(void)
{
    float tmp = 0;
    struct i2c_tmp75 *tmp75;

    tmp75 = tmp75_init(TMP75_SLAVE_REG, TMP75_I2C_DEV, TMP75_OUTPUT_DEV);
    tmp = tmp75->read(tmp75);
    tmp75->exit(tmp75);

    printf("temperature : %f\n", tmp);

    return 0;
}
