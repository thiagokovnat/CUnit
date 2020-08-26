#include "src/CUnit.h"
#include <stdlib.h>


Test(ConditionShouldReturnTrue){

	TEST_ASSERT_TRUE(true);
}


Test(NumbersShouldNotBeEqual){

	int x = 4;
	int y = 5;

	TEST_ASSERT_NOT_EQUAL_INT(x, y);
	
	x++;
	TEST_ASSERT_NOT_EQUAL_INT(x, y);
}

Test(NumberInRange){

	int x = -3;
	int y = -1;
	unsigned int delta = 2;

	TEST_ASSERT_INT_WITHIN(delta, y, x);
}

Test(EqualNullPointers){

	void* a = NULL;
	void* b = NULL;

	TEST_ASSERT_EQUAL_POINTER(a, b);
}


int main(){

	RUN_TEST(ConditionShouldReturnTrue);
	RUN_TEST(NumbersShouldNotBeEqual);
	RUN_TEST(NumberInRange);
	RUN_TEST(EqualNullPointers);

	TEST_PRINT_OVERALL();
}