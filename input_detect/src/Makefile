CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar


SRC = input_detect.c

all:
	$(CC)  input_detect.c   -fPIC -shared -o libinput_detect.so
	$(CC)  -c input_detect.c -o libinput_detect.o -I ../include
	$(AR)  rcv libinput_detect.a libinput_detect.o

clean:
	rm *.so *.o *.a
