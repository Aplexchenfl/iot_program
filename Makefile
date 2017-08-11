

all:
	make -C  gpio_led/main all
	make -C  i2c_tmp75/main all
	make -C  uart_us100/main all
	make -C  rtc_detect/main all
	make -C  input_detect/main all

clean:
	make -C  gpio_led/main   clean
	make -C  i2c_tmp75/main  clean
	make -C  uart_us100/main clean
	make -C  rtc_detect/main clean
	make -C  input_detect/main clean


