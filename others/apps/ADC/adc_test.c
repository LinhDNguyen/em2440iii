/*************************************

NAME:EmbedSky_beep.c
COPYRIGHT:www.embedsky.net

*************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int fd ;
	char temp = 1;

	fd = open("/dev/adc", 0);
	if (fd < 0)
	{
		perror("open ADC device !");
		exit(1);
	}
	
	for( ; ; )
	{
		char buffer[30];
		int len ;

		len = read(fd, buffer, sizeof buffer -1);
		if (len > 0)
		{
			buffer[len] = '\0';
			int value;
			sscanf(buffer, "%d", &value);
			printf("ADC Value: %d\n", value);
		}
		else
		{
			perror("read ADC device !");
			exit(1);
		}
		sleep(1);
	}
adcstop:	
	close(fd);
}
