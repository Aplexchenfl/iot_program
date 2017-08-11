CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar


all:
	$(CC)  uart_us100.c   -fPIC -shared -o libuart_us100.so
	$(CC)  -c uart_us100.c -o libuart_us100.o -I ../include
	$(AR)  rcv libuart_us100.a libuart_us100.o

install:all
	cp *.so   ../lib -rf

clean:
	rm *.so *.o *.a

unstall:
	rm  -rf  ../lib/*.so
