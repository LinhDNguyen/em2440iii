CROSS=arm-linux-

all: buttons

buttons:buttons.c
	$(CROSS)gcc -o buttons buttons.c
	$(CROSS)strip buttons
clean:
	@rm -vf buttons *.o *~
