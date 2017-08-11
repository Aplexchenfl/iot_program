#include "../include/uart_us100.h"

int main(void)
{
    float read_dis_num = 0;

    read_dis_num = read_dis();

    printf(" distant : %f\n", read_dis_num / 1000);

    return 0;
}
