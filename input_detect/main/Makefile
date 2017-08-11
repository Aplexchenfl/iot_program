CC = arm-linux-gnueabihf-gcc

all:
	make -C ../src
	$(CC) main.c -o input_detect -L ../src/ -linput_detect
	arm-linux-gnueabihf-gcc main.c   ../src/input_detect.c -o my_input_detect
	sudo cp my_input_detect  /media/sf_VirtualBox/ -rf
	sync

clean:
	rm -rf my_input_detect  input_detect
	make clean -C ../src


