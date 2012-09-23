CROSS=arm-linux-

all: pthread

pthread:
	$(CROSS)gcc -static -o pthread pthread.c -lpthread
	$(CROSS)strip pthread
clean:
	@rm -vf pthread *.o *~
