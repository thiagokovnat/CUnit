
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wconversion -pedantic -Wtype-limits 


compile: src/CUnit.c test.c
	$(CC)  $(CFLAGS) src/CUnit.c test.c -o test

test: compile
	./test
