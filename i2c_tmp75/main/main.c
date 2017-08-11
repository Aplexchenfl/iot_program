#include "../include/i2c_tmp75.h"

int main(void)
{
    float tmp = 0;

    tmp = read_tmp();
    printf("temperature : %f\n", tmp);

    return 0;
}
