#include "../include/uart_us100.h"

int main(void)
{
    float read_dis_num = 0;
    struct uart_us100 *us100;

    us100 = uart_us100_init(TTY_NODE, NSPEED, NBIT, NEVENT, NSTOP, COMMAND);
    read_dis_num = us100->read(us100);
    us100->exit(us100);

    printf(" distant : %f\n", read_dis_num / 1000);

    return 0;
}
