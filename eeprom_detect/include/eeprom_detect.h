#ifndef __EEPROM_DETECT_H__
#define __EEPROM_DETECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EEPROM_DEVICE "/sys/devices/platform/ocp/44e0b000.i2c/i2c-0/0-0050/eeprom"
#define WRITE_DATA   "abcdefg1234567890\0"

struct eeprom_detect
{
    char write_data[20];
    char read_data[20];
    char eeprom_device[128];

    int (* readorwrite)(struct eeprom_detect *eeprom_det, int readorwrite);
    int (* read)(struct eeprom_detect *eeprom_det);
    int (* write)(struct eeprom_detect *eeprom_det);
    int (* result)(struct eeprom_detect *eeprom_det);
    void (* exit)(struct eeprom_detect *eeprom_det);
};

struct eeprom_detect *eeprom_detect_init(void);
int eeprom_detect_readorwrite(struct eeprom_detect *eeprom_det, int readorwrite);
int eeprom_detect_read(struct eeprom_detect *eeprom_det);
int eeprom_detect_write(struct eeprom_detect *eeprom_det);
int eeprom_detect_result(struct eeprom_detect *eeprom_det);
void eeprom_detect_exit(struct eeprom_detect *eeprom_det);

#endif  /* __EEPROM_DETECT_H__  */

