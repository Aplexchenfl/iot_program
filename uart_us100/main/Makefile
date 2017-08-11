CC = arm-linux-gnueabihf-gcc

all:
	make -C ../src
	$(CC) main.c -o test_tty -L ../src/ -luart_us100
	arm-linux-gnueabihf-gcc main.c   ../src/uart_us100.c -o my_test_dis

clean:
	rm -rf test_tty
	make clean -C ../src


