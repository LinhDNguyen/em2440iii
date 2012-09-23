CROSS=arm-linux-

all: hello-c++

hello-c++:hello-c++.c++
	$(CROSS)g++ -o hello-c++ hello-c++.c++
	$(CROSS)strip hello-c++
clean:
	@rm -vf hello-c++ *.o *~
