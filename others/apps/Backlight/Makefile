CROSS=arm-linux-

all: backlight

backlight:backlight.c
	$(CROSS)gcc -o backlight backlight.c
	$(CROSS)strip backlight
clean:
	@rm -vf backlight *.o *~
