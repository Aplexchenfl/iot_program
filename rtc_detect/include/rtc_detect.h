#ifndef __TIME_DETECT_H__
#define __TIME_DETECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <linux/rtc.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define RTC_DEVICE  "/dev/rtc0"

unsigned int read_rtc_time(void);

#endif /* __TIME_DETECT_H__ */

