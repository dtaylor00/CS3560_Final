# Compiler options
CC = g++
CFLAGS = -Wall -g

count: src/main.cpp
	$(CC) $(CFLAGS) -o $@ $^

doc: Doxyfile
	doxygen

clean:
	rm -rf ./count