# CUnit
Small Unit Testing Library for C


## Assertions

Currently Supported Assertions:

```
TEST_ASSERT_TRUE(bool condition)
TEST_ASSERT_FALSE(bool condition)
TEST_ASSERT_EQUAL_INT(int expected, int actual)
TEST_ASSERT_NOT_EQUAL_INT(int expected, int actual)
TEST_ASSERT_INT_WITHIN(unsigned int delta, int expected, int actual) -> Test if Actual is in +-DELTA of expected.
TEST_ASSERT_EQUAL_STRING(const char* expected, const char* actual)
TEST_ASSERT_NOT_EQUAL_STRING(const char* expected, const char* actual)
TEST_ASSERT_NULL(void* pointer)
TEST_ASSERT_EQUAL_POINTER(void* expected, void* actual)
TEST_ASSERT_EQUAL_INT_ARRAY(int* expected, int* actual, int lengthExpected, int lengthActual)
TEST_ASSERT_EQUAL_CHAR_ARRAY(char* expected, char* actual, int lengthExpected, int lengthActual)
TEST_ASSERT_EQUAL_STRING_ARRAY(char** expected, char** actual, int lengthExpected, int lengthActual)
```

## Test Macro

You can create test functions using the following syntax

```
Test(nameOfTest){
//CONTENT
}
```
You can then execute said test using the following macro

```
RUN_TEST(nameOfTest)
```

## Test Suit

You can create a suit of test to execute all together with one function.
Suit functions
```
CUNIT_TEST_SUIT_T* CREATE_SUIT(char* name)
void ADD_TEST(CUNIT_TEST_SUIT_T* suit, void (*test)(void))
void RUN_SUIT(CUNIT_TEST_SUIT_T* suit)
void DESTROY_SUIT(CUNIT_TEST_SUITE_T* suit) -> Frees the memory used by the test suit.

```
## Overall Status

You can print an overall status of the assertions tested using the following function

```
TEST_PRINT_OVERALL()
```

## Output

```
In Test NumbersShouldNotBeEqual, Assertion in line 34: [OK] 
In Test NumbersShouldNotBeEqual, Assertion in line 37: [FAILURE]
In Test NumberInRange, Assertion in line 46: [OK] 
In Test EqualNullPointers, Assertion in line 54: [OK] 
In Test EqualArrays, Assertion in line 15: [FAILURE]
In Test EqualCharArrays, Assertion in line 25: [FAILURE]
################### Running Suit: ABC ###################
 -> In Test ConditionShouldReturnTrue, Assertion in line 7: [OK] 
 -> In Test EqualNullPointers, Assertion in line 54: [OK] 
 -> In Test EqualArrays, Assertion in line 15: [FAILURE]
#########################################################

-----------------OVERALL------------------------- 
Assertions Passed: [6] 
Assertions Failed: [4] 

```
