CROSS=arm-linux-

sqlite_test:
	$(CROSS)gcc -o sqlite_test sqlite_test.c -lsqlite3
	$(CROSS)strip sqlite_test
clean:
	@rm -vf sqlite_test *.o *~
