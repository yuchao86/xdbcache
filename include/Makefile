all:
	gcc -g -O2 -c *.c
	ar -rc xdbcacheinc.a *.o
	mv xdbcacheinc.a ../lib
	rm -f *.o
debug:
	gcc -g -c *.c -I../ -D _DEBUG -D _X64 -Wall
	ar -rc xdbcacheinc.a *.o
	mv xdbcacheinc.a ../lib
	rm -f *.o
all-mingw:
	gcc -g -O3 -c *.c -I../  -D _MINGW_ -march=i686
	ar -rc xdbcacheinc.a *.o
	mv xdbcacheinc.a ../lib
	rm -f *.o
debug-mingw:
	gcc -g -c *.c -I../ -D _DEBUG -D _MINGW_ -march=i686
	ar -rc xdbcacheinc.a *.o
	mv xdbcacheinc.a ../lib
	rm -f *.o
