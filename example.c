#include "src/CUnit.h"
#include <stdlib.h>


Test(ConditionShouldReturnTrue){

	TEST_ASSERT_TRUE(true);
}

Test(EqualArrays){

	int array1[5] = {0, 1, 2, 3, 4};
	int array2[5] = {0, 1, 3, 3, 4};

	TEST_ASSERT_EQUAL_INT_ARRAY(array1, array2, 5, 5); // Should  fail.

}


Test(EqualCharArrays){

	char array1[3] = {'A', 'B', 'C'};
	char array2[3] = {'A', 'C', 'D'};

	TEST_ASSERT_EQUAL_CHAR_ARRAY(array1, array2, 5, 5); // Should fail.

}

Test(NumbersShouldNotBeEqual){

	int x = 4;
	int y = 5;

	TEST_ASSERT_NOT_EQUAL_INT(x, y);
	
	x++;
	TEST_ASSERT_NOT_EQUAL_INT(x, y); // Should fail.
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

Test(EqualStringArrays){

	char* exp[2] = {"Test", "Test2"};
	char* act[2] = {"Test", "Test2"};

	TEST_ASSERT_EQUAL_STRING_ARRAY(exp, act, 2, 2);
}


int main(){

	RUN_TEST(NumbersShouldNotBeEqual);
	RUN_TEST(NumberInRange);
	RUN_TEST(EqualNullPointers);
	RUN_TEST(EqualArrays);
	RUN_TEST(EqualCharArrays);

	CUNIT_TEST_SUITE_T* suit = CREATE_SUIT("ABC");
	ADD_TEST(suit, ConditionShouldReturnTrue);
	ADD_TEST(suit, EqualNullPointers);
	ADD_TEST(suit, EqualArrays);

	RUN_SUIT(suit);
	DESTROY_SUIT(suit);
	
	RUN_TEST(EqualStringArrays);

	TEST_PRINT_OVERALL();
}