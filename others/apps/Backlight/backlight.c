/*************************************

NAME:backlight.c
COPYRIGHT:www.embedsky.net

*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fb.h>

int main(int argc, char **argv)
{
	int turn;
	int fd;
	if ( argc == 1 )
	{
		fprintf(stderr, "\nUsage: backlight on|off !\n\n");
		exit(1);
	}

	fd = open("/dev/backlight", O_RDWR);
	if (fd < 0) {
		perror("open BackLight device !");
		exit(1);
	}

	if ( strcmp(argv[1], "on" ) == 0)
		turn = 1;
	else if ( strcmp(argv[1], "off" ) == 0)
		turn = 0;
	else 
	{
		fprintf(stderr, "\nUsage: backlight on|off !\n\n");
		exit(1);
	}

	ioctl(fd, turn);
	close(fd);
	return 0;
}

