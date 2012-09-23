CROSS=arm-linux-

all: arm-udptest x86-udptest

arm-udptest:
	$(CROSS)gcc -o arm-udptest UDP.c
	$(CROSS)strip arm-udptest
x86-udptest:
	gcc -o x86-udptest UDP.c
	strip x86-udptest
clean:
	@rm -vf *-udptest *.o *~
