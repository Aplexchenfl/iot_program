#include "../include/input_detect.h"

int detect_usb_keyboard(void)
{
    char *tmp = NULL;
    int fd, retval, detect_num = 0;

    tmp = malloc(BUF_SIZE);

    fd = open(INPUT_DEVICE, O_RDONLY);
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

    while (*tmp++ != '\0')
    {
        if(*tmp == 'K')
        {
            if ((strncmp(tmp, "Keyboard", 8)) == 0)
            {
                detect_num = 1;
                break;
            }
        }
    }

    close(fd);

    free(tmp);

    return detect_num;
}

int detect_usb_mouse(void)
{
    char *tmp = NULL;
    int fd, retval, detect_num = 0;

    tmp = malloc(BUF_SIZE);

    fd = open(INPUT_DEVICE, O_RDONLY);
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

    while (*tmp++ != '\0')
    {
        if(*tmp == 'M')
        {
            if ((strncmp(tmp, "MOUSE", 5)) == 0)
            {
                detect_num = 1;
                break;
            }
        }
    }

    close(fd);

    free(tmp);

    return detect_num;
}

int detect_touch_screen(void)
{
    char *tmp = NULL;
    int fd, retval, detect_num = 0;

    tmp = malloc(BUF_SIZE);

    fd = open(INPUT_DEVICE, O_RDONLY);
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

    while (*tmp++ != '\0')
    {
        if(*tmp == 't')
        {
            if ((strncmp(tmp, "ti-tsc", 6)) == 0)
            {
                detect_num = 1;
                break;
            }
        }
    }

    close(fd);

    free(tmp);

    return detect_num;
}

