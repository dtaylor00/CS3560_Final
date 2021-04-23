# Compiler options
CC = g++
CFLAGS = -Wall -g

count: src/main.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf ./count