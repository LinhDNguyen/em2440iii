CFLAGS=-g -Wall
CC=arm-linux-gcc
AR=arm-linux-ar
RANLIB=arm-linux-ranlib
STRIP =arm-linux-strip
LIBS=-L./ -lcgic

all: libcgic.a cgictest.cgi capture

install: libcgic.a
	cp libcgic.a /opt/EmbedSky/4.3.3/arm-none-linux-gnueabi/libc/armv4t/lib
	cp cgic.h /opt/EmbedSky/4.3.3/arm-none-linux-gnueabi/libc/usr/include
	@echo libcgic.a is in /opt/EmbedSky/4.3.3/arm-none-linux-gnueabi/libc/armv4t/lib. cgic.h is in /opt/EmbedSky/4.3.3/arm-none-linux-gnueabi/libc/usr/include.

libcgic.a: cgic.o cgic.h
	rm -f libcgic.a
	$(AR) rc libcgic.a cgic.o
	$(RANLIB) libcgic.a

#mingw32 and cygwin users: replace .cgi with .exe

cgictest.cgi: cgictest.o libcgic.a
	$(CC) $(CFLAGS) cgictest.o -o cgictest.cgi ${LIBS}

capture: capture.o libcgic.a
	$(CC) $(CFLAGS) capture.o -o capture ${LIBS}
	$(STRIP) capture

clean:
	rm -f *.o *.a cgictest.cgi capture

