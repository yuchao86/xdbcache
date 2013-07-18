all:
	gcc -O3 -g -c *.c -I./include
	ar -rc xdbcache.a *.o
	rm -f *.o
debug:
	gcc -g -c *.c -I./include
	ar -rc xdbcache.a *.o
	rm -f *.o
