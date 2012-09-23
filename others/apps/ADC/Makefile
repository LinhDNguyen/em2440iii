CROSS=arm-linux-

all: adc_test

adc_test: adc_test.c
	$(CROSS)gcc -o adc_test adc_test.c
	$(CROSS)strip adc_test
clean:
	@rm -vf adc_test *.o *~
