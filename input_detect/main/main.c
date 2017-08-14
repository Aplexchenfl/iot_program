#include "../include/input_detect.h"

int main(void)
{
    int result = 0;

    struct device_detect *input_device;

    input_device = device_detect_init(USB_KEYBOARD_NAME, USB_KEYBOARD_NAME_SIZE, USB_MOUSE_NAME, USB_MOUSE_NAME_SIZE, TOUCH_SCREEN_NAME, TOUCH_SCREEN_NAME_SIZE, INPUT_DEVICE);

    result = input_device->detect_usb_keyboard(input_device);
    if (result)
        printf(" Detect keyboard ---\n");
    else
        printf(" No keyboard ---\n");

    result = 0;
    result = input_device->detect_usb_mouse(input_device);
    if (result)
        printf(" Detect mouse ---\n");
    else
        printf(" No usb mouse ---\n");

    result = 0;
    result = input_device->detect_touch_screen(input_device);
    if (result)
        printf(" Detect touch screen ---\n");
    else
        printf(" No touch screen ---\n");


    return 0;
}

