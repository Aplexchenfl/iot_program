#include "../include/input_detect.h"

int main(void)
{
    int result = 0;

    result = detect_usb_keyboard();
    if (result)
        printf(" Detect keyboard ---\n");
    else
        printf(" No keyboard ---\n");

    result = 0;
    result = detect_usb_mouse();
    if (result)
        printf(" Detect mouse ---\n");
    else
        printf(" No usb mouse ---\n");

    result = 0;
    result = detect_touch_screen();
    if (result)
        printf(" Detect touch screen ---\n");
    else
        printf(" No touch screen ---\n");

    return 0;
}

