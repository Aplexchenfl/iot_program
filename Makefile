

all:
	make -C  gpio_led/main all
	make -C  i2c_tmp75/main all
	make -C  uart_us100/main all
	make -C  rtc_detect/main all
	make -C  input_detect/main all
	make -C  eeprom_detect/main all
	make -C  usb_udisk_detect/main all
	make -C  buzzer_detect/main all

install:all
	make -C  gpio_led/main install
	make -C  i2c_tmp75/main install
	make -C  uart_us100/main install
	make -C  rtc_detect/main install
	make -C  input_detect/main install
	make -C  eeprom_detect/main install
	make -C  usb_udisk_detect/main install
	make -C  buzzer_detect/main  install


clean:
	make -C  gpio_led/main   clean
	make -C  i2c_tmp75/main  clean
	make -C  uart_us100/main clean
	make -C  rtc_detect/main clean
	make -C  input_detect/main clean
	make -C  eeprom_detect/main clean
	make -C  usb_udisk_detect/main clean
	make -C  buzzer_detect/main clean


