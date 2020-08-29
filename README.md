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

## Overall Status

You can print an overall status of the assertions tested using the following function

```
TEST_PRINT_OVERALL()
```
