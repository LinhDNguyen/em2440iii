CROSS=arm-linux-

all: led-player

led-player:led-player.c
	$(CROSS)gcc -o led-player led-player.c
	$(CROSS)strip led-player
clean:
	@rm -vf led-player *.o *~
