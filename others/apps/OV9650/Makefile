CC=arm-linux-gcc
LD=arm-linux-ld

CAM_EXEC=camera_test
CAM_OBJS=camera_test.o

CFLAGS +=
LDFLAGS +=

all:$(CAM_EXEC) $(AV_EXEC)
	rm *.o

$(CAM_EXEC):$(CAM_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(CAM_OBJS) $(LDLIBS$(LDLIBS_$@))

clean:
	-rm -f $(CAM_EXEC) *.elf *.gdb *.o
