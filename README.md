
###  gpio_led

```c
    header : gpio_led/include/gpio_led.h
    src    : gpio_led/src/gpio_led.c
    main   : gpio_led/main/main.c

    function :
    void gpio_led_init(struct iot_gpio *, int io_count, int *, int sleep_one_run, int sleep_all_run);
        gpio led 初始化函数.

    void gpio_led_control(int gpio_num, int gpio_out);
        gpio led 控制函数。

    void gpio_led_on(int gpio_num);
        gpio 设置为高函数。

    void gpio_led_off(int gpio_num);
        gpio 设置为低函数。

    void gpio_led_release(struct iot_gpio *);
        gpio 退出释放函数。

    void gpio_led_run(struct iot_gpio *);
        跑马灯函数。
```

###  i2c_tmp75

```c
    header : i2c_tmp75/include/i2c_tmp75.h
    src    : i2c_tmp75/src/i2c_tmp75.c
    main   : i2c_tmp75/main/main.c

    function :
    struct i2c_tmp75 *tmp75_init(void);
        申请并初始化一个 i2c_tmp75 结构体。

    float tmp75_read(struct i2c_tmp75 *);
        读取 tmp75 传感器返回的数值。

    void tmp75_release(struct i2c_tmp75 *);
        退出释放 i2c_tmp75
```

###  uart_us100

```c
    header : uart_us100/include/uart_us100.h
    src    : uart_us100/src/uart_us100.c
    main   : uart_us100/main/main.c
    function :
    struct uart_us100 *uart_us100_init(void);
        申请以及初始化一个 uart_us100 结构体

    int uart_us100_read(struct uart_us100 *);
        读取 us100 上返回的数据

    void uart_us100_exit(struct uart_us100 *);
        退出以及释放函数

    int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop);
        设置串口的属性
```

###  input_detect

```c
    header : input_detect/include/input_detect.h
    src    : input_detect/src/input_detect.c
    main   : input_detect/main/main.c
    function :
    struct device_detect *device_detect_init(void);
        申请并初始化 device_detect 结构体
    int detect_spe_device(char *device_name, char *path, int device_name_size);
        检测对应的设备
    int detect_usb_keyboard(struct device_detect *input_detect);
        检测 usb 键盘是否存在
    int detect_usb_mouse(struct device_detect *input_detect);
        检测 usb 鼠标是否存在
    int detect_touch_screen(struct device_detect *input_detect);
        检测 touch 是否存在，因为目前touch 是采用AD,只要是驱动存在即可检验成功
    void detect_release(struct device_detect *input_detect);
        退出释放函数。
```

###  rtc_detect

```c
    header : rtc_detect/include/rtc_detect.h
    src    : rtc_detect/src/rtc_detect.c
    main   : rtc_detect/main/main.c
    function :
    struct rtc_detect *rtc_detect_init(void);
        申请并初始化一个 rtc_detect 结构体
    int rtc_detect_read(struct rtc_detect *rtc_det);
        读取 rtc 的时间
    unsigned long rtc_detect_read_timestamp(void);
        返回时间戳
    void rtc_detect_display(struct rtc_detect *rtc_det);
        显示 rtc 时间
    void rtc_detect_release(struct rtc_detect *rtc_det);
        退出及释放函数
```

###  eeprom_detect

```c
    header : eeprom_detect/include/eeprom_detect.h
    src    : eeprom_detect/src/eeprom_detect.c
    main   : eeprom_detect/main/main.c
    function :
    struct eeprom_detect *eeprom_detect_init(void);
        申请并初始化一个 eeprom_detect 结构体。

    int eeprom_detect_readorwrite(struct eeprom_detect *eeprom_det, int readorwrite);
        执行对 eeprom 或者写的操作。 readorwrite == 1 为 read, 0 为 write

    int eeprom_detect_read(struct eeprom_detect *eeprom_det);
        执行对 eeprom 读的操作

    int eeprom_detect_write(struct eeprom_detect *eeprom_det);
        执行对 eeprom 写的操作

    int eeprom_detect_result(struct eeprom_detect *eeprom_det);
        返回写入以及读取的数据的比较结构，0 为相同，非0 表示出错。

    void eeprom_detect_release(struct eeprom_detect *eeprom_det);
        退出函数
```

###  usb_udisk_detect

```c
    header : usb_udisk_detect/include/usb_udisk_detect.h
    src    : usb_udisk_detect/src/usb_udisk_detect.c
    main   : usb_udisk_detect/main/main.c
    function :
    struct usb_udisk_detect *usb_udisk_detect_init(void);
        申请并初始化一个 usb_udisk_detect 函数
    int usb_udisk1_detect_result(struct usb_udisk_detect *usb_udisk);
        返回 udisk1 的检测结果
    int usb_udisk2_detect_result(struct usb_udisk_detect *usb_udisk);
        返回 udisk2 的检测结果
    void usb_udisk_detect_release(struct usb_udisk_detect *usb_udisk);
        退出以及释放函数
```
