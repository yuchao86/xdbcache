all:
	gcc -g -O3 -c *.c -I../include -I../include -I../
xdbserver2:xdbserver2.o
	gcc -g -O3 -o xdbserver2 xdbserver2.o db_protocal.o ../xdbcacheinc.a -lpthread -lrt -ltcmalloc	
client3:testclient3.o
	gcc -g -O3 -o client3 testclient3.o db_protocal.o ../xdbcacheinc.a -lpthread -lrt	-ltcmalloc
