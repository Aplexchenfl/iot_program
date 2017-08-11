CC = arm-linux-gnueabihf-gcc

all:
	make -C ../src
	$(CC)	  main.c   -o gpio_led -L ../src/ -lgpio_led
	$(CC)  	  main.c   ../src/gpio_led.c  -o my_gpio_led

clean:
	rm gpio_led  my_gpio_led -rf
	make -C ../src clean

