OBJECTS = main.o
SRCS = main.cpp

CC = g++
CFLAGS = -g -c

TARGET = blockchain

blockchain.o:
	$(CC) -c blockchain.hpp blockchain.cpp

main.o:
	$(CC) -c main.cpp

$(TARGET): $(OBJECTS)
	$(CC) -o main.o blockchain.o -l:libcryptopp.a