#include "src/CUnit.h"
#include <stdlib.h>


Test(ConditionShouldReturnTrue){

	TEST_ASSERT_TRUE(true);
}

Test(EqualArrays){

	int array1[5] = {0, 1, 2, 3, 4};
	int array2[5] = {0, 1, 3, 3, 4};

	TEST_ASSERT_EQUAL_INT_ARRAY(array1, array2, 5, 5);

}


Test(EqualCharArrays){

	char array1[3] = {'A', 'B', 'C'};
	char array2[3] = {'A', 'C', 'D'};

	TEST_ASSERT_EQUAL_CHAR_ARRAY(array1, array2, 5, 5);

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
	RUN_TEST(EqualArrays);
	RUN_TEST(EqualCharArrays);

	TEST_PRINT_OVERALL();
}