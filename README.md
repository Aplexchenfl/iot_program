
###  gpio_led

```c
    header : gpio_led/include/gpio_led.h
    src    : gpio_led/src/gpio_led.c
    main   : gpio_led/main/main.c

    function :
    void gpio_led_start(void);
    当调用这个函数的时候，MIO上的gpio会先从小到大置为高电平，
    然后再从大到小置为高电平，紧接着所有的gpio置为高电平两秒，最后全部置为低电平。
```

###  i2c_tmp75

```c
    header : i2c_tmp75/include/i2c_tmp75.h
    src    : i2c_tmp75/src/i2c_tmp75.c
    main   : i2c_tmp75/main/main.c

    function :
    float read_tmp(void);
    当调用这个函数的时候，返回一个温度值.
```

###  uart_us100

```c
    header : uart_us100/include/uart_us100.h
    src    : uart_us100/src/uart_us100.c
    main   : uart_us100/main/main.c
    function :
    int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop);
    该函数为配置终端的函数，在read_dis 里面已经调用。
    float read_dis(void);
    该函数返回为 US-100 所测量的距离。
```

###  input_detect

```c
    header : input_detect/include/input_detect.h
    src    : input_detect/src/input_detect.c
    main   : input_detect/main/main.c
    function :
    int detect_usb_keyboard(void);
    检测USB 键盘是否存在，如果存在返回1，不存在返回0.
    int detect_usb_mouse(void);
    检测USB鼠标是否存在，存在返回1，不存在返回0.
    int detect_touch_screen(void);
    检测 touch screen 驱动是否存在，如果存在返回1，不存在返回0.
```

###  rtc_detect

```c
    header : rtc_detect/include/rtc_detect.h
    src    : rtc_detect/src/rtc_detect.c
    main   : rtc_detect/main/main.c
    function :
    unsigned int read_rtc_time(void);
    返回时间戳.
```
