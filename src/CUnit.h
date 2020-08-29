#ifndef __CUNIT_H__
#define __CUNIT_H__
#include <stdbool.h>

#define TEST_ASSERT_TRUE(x) 									CUNIT_ASSERT_TRUE(x, __func__, __LINE__)
#define TEST_ASSERT_FALSE(x) 									CUNIT_ASSERT_FALSE(x, __func__, __LINE__)
#define TEST_ASSERT_EQUAL_INT(x, y) 							CUNIT_ASSERT_EQUAL_INT(x, y, __func__, __LINE__)
#define TEST_ASSERT_NOT_EQUAL_INT(x, y) 						CUNIT_ASSERT_NOT_EQUAL_INT(x, y, __func__, __LINE__)
#define TEST_ASSERT_INT_WITHIN(x, y, z) 						CUNIT_ASSERT_INT_WITHIN(x, y, z, __func__, __LINE__)
#define TEST_ASSERT_EQUAL_STRING(x, y) 							CUNIT_ASSERT_EQUAL_STRING(x, y, __func__, __LINE__)
#define TEST_ASSERT_NOT_EQUAL_STRING(x, y)						CUNIT_ASSERT_NOT_EQUAL_STRING(x, y, __func__, __LINE__)
#define TEST_ASSERT_NULL(x)										CUNIT_ASSERT_NULL(x, __func__, __LINE__)
#define TEST_ASSERT_EQUAL_POINTER(x, y)							CUNIT_ASSERT_EQUAL_POINTER(x, y, __func__, __LINE__)
#define TEST_ASSERT_EQUAL_INT_ARRAY(x, y, z, j)					CUNIT_ASSERT_EQUAL_INT_ARRAY(x, y, z, j, __func__, __LINE__)
#define TEST_ASSERT_EQUAL_CHAR_ARRAY(x, y, z, j)				CUNIT_ASSERT_EQUAL_CHAR_ARRAY(x, y, z, j, __func__, __LINE__)
	





#define Test(name) 												void name()


void RUN_TEST(void (*test)());

void TEST_PRINT_OVERALL();

void CUNIT_ASSERT_TRUE(bool condition, const char* test, int line);

void CUNIT_ASSERT_FALSE(bool condition, const char* test, int line);

void CUNIT_ASSERT_EQUAL_INT(int x, int y, const char* test, int line);

void CUNIT_ASSERT_NOT_EQUAL_INT(int x, int y, const char* test, int line);

void CUNIT_ASSERT_INT_WITHIN(unsigned int delta, int expected, int num, const char* test, int line);

void CUNIT_ASSERT_EQUAL_STRING(const char* expected, const char* actual, const char* test, int line);

void CUNIT_ASSERT_EQUAL_POINTER(void* expected, void* actual, const char* test, int line);

void CUNIT_ASSERT_NULL(void* pointer, const char* test, int line);

void CUNIT_ASSERT_EQUAL_INT_ARRAY(int* expected, int* actual, int lengthExpected, int lengthActual, const char* test, int line);

void CUNIT_ASSERT_EQUAL_CHAR_ARRAY(char* expected, char* actual, int lengthExpected, int lengthActual, const char* test, int line);




#endif