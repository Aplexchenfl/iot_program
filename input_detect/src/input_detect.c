#include "../include/input_detect.h"

struct device_detect *device_detect_init(char *usb_keyboard_name, int usb_keyboard_name_size, char *usb_mouse_name, int usb_mouse_name_size, char *touch_screen_name, int touch_screen_name_size, char *detect_path)
{
    struct device_detect *input_detect;

    input_detect = malloc(sizeof(struct device_detect));
    if (!input_detect)
        return NULL;

    memset(input_detect, 0, sizeof(struct device_detect));

    input_detect->usb_keyboard_name_size = usb_keyboard_name_size;
    input_detect->usb_mouse_name_size = usb_mouse_name_size;
    input_detect->touch_screen_name_size = touch_screen_name_size;

    strcpy(input_detect->usb_keyboard_name, usb_keyboard_name);
    strcpy(input_detect->usb_mouse_name, usb_mouse_name);
    strcpy(input_detect->touch_screen_name, touch_screen_name);
    strcpy(input_detect->detect_path, detect_path);

    input_detect->init = device_detect_init;
    input_detect->detect_usb_keyboard = detect_usb_keyboard;
    input_detect->detect_usb_mouse = detect_usb_mouse;
    input_detect->detect_touch_screen = detect_touch_screen;
    input_detect->detece_spe_device = detece_spe_device;
    input_detect->exit = detect_exit;

    return input_detect;
}

int detece_spe_device(char *device_name, char *path, int device_name_size)
{
    char tmp[BUF_SIZE], *tmp_buf = tmp;
    int fd, retval, detect_num = 0, i = 0;


    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open ");
        return -1;
    }

    retval = read(fd, tmp, BUF_SIZE);
    if (retval < 0)
    {
        perror("read ");
        close(fd);
        return -1;
    }

    while (*tmp_buf++ != '\0')
    {
        if(tmp_buf[0] == device_name[0])
        {
            if ((strncmp(tmp_buf, device_name, device_name_size)) == 0)
            {
                detect_num = 1;
                break;
            }
        }
    }

    close(fd);

    return detect_num;
}

int detect_usb_keyboard(struct device_detect *input_detect)
{
    return detece_spe_device(input_detect->usb_keyboard_name, input_detect->detect_path, input_detect->usb_keyboard_name_size);
}

int detect_usb_mouse(struct device_detect *input_detect)
{
    return detece_spe_device(input_detect->usb_mouse_name, input_detect->detect_path, input_detect->usb_mouse_name_size);
}

int detect_touch_screen(struct device_detect *input_detect)
{
    return detece_spe_device(input_detect->touch_screen_name, input_detect->detect_path, input_detect->touch_screen_name_size);
}

void detect_exit(struct device_detect *input_detect)
{
    free(input_detect);
}
