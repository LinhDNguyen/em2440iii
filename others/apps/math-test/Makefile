CROSS=arm-linux-

all: mathtest

mathtest:mathtest.c
	$(CROSS)gcc -o mathtest mathtest.c -lm
	$(CROSS)strip mathtest
clean:
	@rm -vf mathtest *.o *~
