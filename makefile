
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wconversion -pedantic -Wtype-limits 


compile: src/CUnit.c example.c
	$(CC)  $(CFLAGS) src/CUnit.c example.c -o test

test: compile
	./test
