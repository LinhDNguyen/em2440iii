CROSS=arm-linux-

all: beep

beep: beep.c
	$(CROSS)gcc -o beep beep.c
	$(CROSS)strip beep
clean:
	@rm -vf beep *.o *~
