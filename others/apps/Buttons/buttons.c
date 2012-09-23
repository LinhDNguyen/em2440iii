#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

int main(void)
{
	int i;
	int buttons_fd;
	int key_value[4];

	/*打开键盘设备文件*/
	buttons_fd = open("/dev/IRQ-Test", 0);
	if (buttons_fd < 0)
	{
		perror("open device buttons");
		exit(1);
	}

	for (;;)
	{
		fd_set rds;
		int ret;

		FD_ZERO(&rds);
		FD_SET(buttons_fd, &rds);

		/*使用系统调用select检查是否能够从/dev/EmbedSky-buttons设备读取数据*/
		ret = select(buttons_fd + 1, &rds, NULL, NULL, NULL);
		
		/*读取出错则退出程序*/
		if (ret < 0)
		{
			perror("select");
			exit(1);
		}
		
		if (ret == 0)
		{
			printf("Timeout.\n");
		} 
		/*能够读取到数据*/
		else if (FD_ISSET(buttons_fd, &rds))
		{
			/*开始读取键盘驱动发出的数据，注意key_value和键盘驱动中定义为一致的类型*/
			int ret = read(buttons_fd, key_value, sizeof(key_value));
			if (ret != sizeof(key_value))
			{
				if (errno != EAGAIN)
					perror("read buttons\n");
				continue;
			}
			else
			{
				/*打印键值*/
				for (i = 0; i < 4; i++)
					if(key_value[i] != 0)
						printf("K%d %s, key value = 0x%02x\n", i+1, (key_value[i] & 0x80) ? "released" : key_value[i] ? "pressed down" : "", key_value[i]);
			}
				
		}
	}

	/*关闭设备文件句柄*/
	close(buttons_fd);
	return 0;
}
