# Compiler options
CC = g++
CFLAGS = -Wall -g

count: src/main.cpp
	$(CC) $(CFLAGS) -o count src/main.cpp

doc: Doxyfile
	doxygen

check: src/main.cpp count README.md
	mkdir check
	cppcheck --enable=all --output-file="./check/cppcheck-output.txt" src/main.cpp
	valgrind --leak-check=full --show-leak-kinds=all --log-file="./check/valgrind-output.txt" ./count README.md

test: tests/testcases.cpp
	$(CC) $(CFLAGS) -o count_test tests/testcases.cpp

clean:
	rm -rf ./count