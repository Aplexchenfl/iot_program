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

#define USB_KEYBOARD_NAME       "Keyboard"
#define USB_KEYBOARD_NAME_SIZE  8
#define USB_MOUSE_NAME          "MOUSE"
#define USB_MOUSE_NAME_SIZE     5
#define TOUCH_SCREEN_NAME       "ti-tsc"
#define TOUCH_SCREEN_NAME_SIZE  6

struct device_detect
{
    char usb_keyboard_name[32];
    int usb_keyboard_name_size;
    char usb_mouse_name[32];
    int usb_mouse_name_size;
    char touch_screen_name[32];
    int touch_screen_name_size;
    char detect_path[32];

    struct device_detect *(* init)(char *usb_keyboard_name, int usb_keyboard_name_size, char *usb_mouse_name, int usb_mouse_name_size, char *touch_screen_name, int touch_screen_name_size, char *detect_path);
    int (* detect_usb_keyboard)(struct device_detect *);
    int (* detect_usb_mouse)(struct device_detect *);
    int (* detect_touch_screen)(struct device_detect *);
    int (* detece_spe_device)(char *device_name, char *path, int device_name_size);
    void (* exit)(struct device_detect *);
};

struct device_detect *device_detect_init(char *usb_keyboard_name, int usb_keyboard_name_size, char *usb_mouse_name, int usb_mouse_name_size, char *touch_screen_name, int touch_screen_name_size, char *detect_path);
int detece_spe_device(char *device_name, char *path, int device_name_size);
int detect_usb_keyboard(struct device_detect *input_detect);
int detect_usb_mouse(struct device_detect *input_detect);
int detect_touch_screen(struct device_detect *input_detect);
void detect_exit(struct device_detect *input_detect);

#endif /* __INPUT_DETECT_H__ */
