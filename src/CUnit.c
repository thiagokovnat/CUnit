#include "CUnit.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>

static int success_count = 0;
static int failure_count = 0;

#define ANSI_COLOR_GREEN   "\x1b[1m\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED	"\x1b[1m\x1b[31m"
#define ANSI_COLOR_X	"\x1b[1m\x1b[33m"

void RUN_TEST(void (*test)()){
	test();
}


void TEST_PRINT_OVERALL(){

	printf("\n-----------------" ANSI_COLOR_X "OVERALL" ANSI_COLOR_RESET "------------------------- \n");

	printf("Assertions Passed: " ANSI_COLOR_GREEN "[%i] \n" ANSI_COLOR_RESET, success_count);
	printf("Assertions Failed: " ANSI_COLOR_RED "[%i] \n" ANSI_COLOR_RESET, failure_count);

}

static void PRINT_SUCCESS(const char* test, int line){

	printf("In Test %s, Assertion in line %i: " ANSI_COLOR_GREEN "[OK] \n" ANSI_COLOR_RESET, test, line);
	success_count++;

}

static void PRINT_FAILURE(const char* test, int line){

	printf("In Test %s, Assertion in line %i: " ANSI_COLOR_RED "[FAILURE]\n" ANSI_COLOR_RESET, test, line);
	failure_count++;
}


void CUNIT_ASSERT_TRUE(bool condition, const char* test, int line){

	if(condition)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}


void CUNIT_ASSERT_FALSE(bool condition, const char* test, int line){

	if(!condition)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}

void CUNIT_ASSERT_EQUAL_INT(int x, int y, const char* test, int line){

	if(x == y)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}

void CUNIT_ASSERT_NOT_EQUAL_INT(int x, int y, const char* test, int line){

	if(x != y)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);

}

void CUNIT_ASSERT_INT_WITHIN(unsigned int delta, int expected, int num, const char* test, int line){

	if(num <= (expected + (int) delta) && num >= (expected - (int) delta))
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}


void CUNIT_ASSERT_EQUAL_STRING(const char* expected, const char* actual, const char* test, int line){

	if(strcmp(expected, actual) == 0)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}

void CUNIT_ASSERT_NOT_EQUAL_STRING(const char* expected, const char* actual, const char* test, int line){

	if(strcmp(expected, actual) != 0)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}

void CUNIT_ASSERT_EQUAL_POINTER(void* expected, void* actual, const char* test, int line){

	if(expected == actual)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}

void CUNIT_ASSERT_NULL(void* pointer, const char* test, int line){

	if(!pointer)
		PRINT_SUCCESS(test, line);
	else
		PRINT_FAILURE(test, line);
}


void CUNIT_ASSERT_EQUAL_INT_ARRAY(int* expected, int* actual, int lengthExpected, int lengthActual, const char* test, int line){

	if (lengthExpected != lengthActual){
		PRINT_FAILURE(test, line);
		return;
	}

	for (int i = 0; i < lengthActual; ++i){

		if (expected[i] != actual[i]){
			PRINT_FAILURE(test, line);
			return;
		}
	}

	PRINT_SUCCESS(test, line);
}

void CUNIT_ASSERT_EQUAL_CHAR_ARRAY(char* expected, char* actual, int lengthExpected, int lengthActual, const char* test, int line){

	if (lengthExpected != lengthActual){
		PRINT_FAILURE(test, line);
		return;
	}

	for (int i = 0; i < lengthActual; ++i){

		if (expected[i] != actual[i]){
			PRINT_FAILURE(test, line);
			return;
		}
	}

	PRINT_SUCCESS(test, line);
}