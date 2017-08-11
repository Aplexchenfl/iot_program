#ifndef __INPUT_DETECT_H__
#define __INPUT_DETECT_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_DEVICE  "/proc/bus/input/devices"
#define BUF_SIZE  2048

int detect_usb_keyboard(void);
int detect_usb_mouse(void);
int detect_touch_screen(void);

#endif /* __INPUT_DETECT_H__ */
