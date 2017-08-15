CC = arm-linux-gnueabihf-gcc

NAME = gpio_led

all:
	make -C ../src
	$(CC)	  main.c   -o $(NAME) -L ../src/ -l$(NAME)
	$(CC)  	  main.c   ../src/$(NAME).c  -o my_$(NAME)

install:
	sudo cp my_$(NAME) /media/sf_VirtualBox   -rf
	sync

clean:
	rm $(NAME)  my_$(NAME) -rf
	make -C ../src clean

