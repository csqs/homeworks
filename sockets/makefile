all:client server client_test
client : client.o
	gcc -o client client.o
client.o : client.c
	gcc -c client.c
server : server.c
	gcc server.c /usr/local/lib/libhiredis.dylib -o server -fPIC
client_test : client_test.c
	gcc client_test.c -o client_test

