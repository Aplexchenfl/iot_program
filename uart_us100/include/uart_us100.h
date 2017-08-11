#ifndef _UART_US100_H__
#define _UART_US100_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop);
float read_dis(void);

#endif
