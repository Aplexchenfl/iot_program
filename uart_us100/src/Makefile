CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar

NAME = uart_us100
SOURCE = $(NAME).c
SHARD_LIB = lib$(NAME).so
STATIC_LIB = lib$(NAME).o
STATIC_LIB_A = lib$(NAME).a


all:
	$(CC)  $(SOURCE)   -fPIC -shared -o   $(SHARD_LIB)
	$(CC)  -c   $(SOURCE)  -o  $(STATIC_LIB)  -I ../include
	$(AR)  rcv   $(STATIC_LIB_A)   $(STATIC_LIB)

clean:
	rm *.so *.o *.a

