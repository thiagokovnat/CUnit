#include "src/CUnit.h"


void ConditionShouldReturnTrue(){

	bool ex = true;

	TEST_ASSERT_TRUE(ex);
}


void NumbersShouldNotBeEqual(){

	int x = 4;
	int y = 5;

	TEST_ASSERT_NOT_EQUAL_INT(x, y);
}

void NumberInRange(){

	int x = -3;
	int y = -1;
	unsigned int delta = 2;

	TEST_ASSERT_INT_WITHIN(delta, y, x);
}


int main(){


	ConditionShouldReturnTrue();

	NumbersShouldNotBeEqual();

	NumberInRange();

	TEST_ASSERT_EQUAL_STRING("Okay", "Okayy");

	TEST_PRINT_OVERALL();
}