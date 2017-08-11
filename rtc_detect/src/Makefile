CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar


SRC = rtc_detect.c
OBJ = librtc_detect.o
SHARED_OBJ = librtc_detect.so
OBJ_A = librtc_detect.a


all:
	$(CC)  $(SRC)   -fPIC -shared -o $(SHARED_OBJ)
	$(CC)  -c $(SRC) -o $(OBJ) -I ../include
	$(AR)  rcv $(OBJ_A)   $(OBJ)

clean:
	rm *.so *.o *.a
