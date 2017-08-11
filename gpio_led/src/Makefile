CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar

all:
	$(CC)  gpio_led.c   -fPIC -shared -o   libgpio_led.so
	$(CC)  -c   gpio_led.c  -o  libgpio_led.o -I ../include
	$(AR)  rcv  libgpio_led.a  libgpio_led.o

clean:
	rm *.so *.o *.a

