CC = arm-linux-gnueabihf-gcc

all:
	make -C ../src
	$(CC)	  main.c -o read_tmp -L ../src/ -li2c_tmp75
	$(CC)  	  main.c   ../src/i2c_tmp75.c  -o my_read_test

clean:
	rm read_tmp  my_read_test -rf
	make -C ../src clean

