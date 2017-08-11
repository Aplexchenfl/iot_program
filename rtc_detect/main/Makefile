CC = arm-linux-gnueabihf-gcc

SRC = main.c
LIB = rtc_detect
SRC1 = ../src/rtc_detect.c
TARGET = rtc_detect
TARGET1 = my_rtc_detect

all:
	make -C ../src
	$(CC) main.c -o $(TARGET) -L ../src/ -l$(LIB)
	arm-linux-gnueabihf-gcc $(SRC)   $(SRC1) -o   $(TARGET1)
	sudo cp $(TARGET1)  /media/sf_VirtualBox/ -rf
	sync

clean:
	rm -rf  $(TARGET1) $(TARGET)
	make clean -C ../src


