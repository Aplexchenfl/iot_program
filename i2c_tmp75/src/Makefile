CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar

all:
	$(CC)  i2c_tmp75.c   -fPIC -shared -o   libi2c_tmp75.so
	$(CC)  -c   i2c_tmp75.c  -o  libi2c_tmp75.o -I ../include
	$(AR)  rcv  libi2c_tmp75.a  libi2c_tmp75.o

clean:
	rm *.so *.o *.a

