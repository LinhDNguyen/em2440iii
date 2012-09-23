/*************************************

NAME:leds.c
COPYRIGHT:www.embedsky.net

*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
struct spihr
{
	unsigned short status;
	unsigned short dat;
};
int main(int argc, char **argv)
{
	int fd;
	unsigned long temp =0;
	int i;

	fd = open("/dev/PWM-Test", 0);
	if (fd < 0) {


		perror("open device EmbedSky-BEEP");
		exit(1);
	}
	printf("Please enter the times number (0 is stop) :\n");

	for(i=0;;i++)
	{
		scanf("%d",&temp);
		printf("times = %d \n",temp);
		if(temp == 0)
		{
			ioctl(fd, 0);
			printf("Stop Control Beep!\n");
			break;
		}
		else
		{
			ioctl(fd, 1, temp);
		}
	}
	close(fd);
	return 0;
}

