#include "../makeString.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>

/*-----------------------test functions--------------------------*/

void makeString_ShouldReturnNullOnInvalidParams(void)
{
    //	fixture setup
    char	str_valid[] = "valid",
		str_empty[] = "";
    int	length_valid = 1,
	length_zero = 0,
        length_negative = -1,
	length_overflow = 30;

    //	system under control and verify

    //	test invalid string ptr
    CU_ASSERT_EQUAL(makeString(NULL, length_valid), NULL);
    CU_ASSERT_EQUAL(makeString(str_empty, length_valid), NULL);
    //	test invalid string length
    CU_ASSERT_EQUAL(makeString(str_valid, length_zero), NULL);
    CU_ASSERT_EQUAL(makeString(str_valid, length_negative), NULL);
    //	test incorrect string size with `length`
    CU_ASSERT_EQUAL(makeString(str_valid, length_overflow), NULL);
}

void makeString_ShouldReturnValidStringOnValidParam(void)
{
    //	fixture setup
    char	str[] = "valid string";
    int		length = 5;
    char*	actual = NULL;

    //	system under control 
    actual = makeString(str, length);
    //	verify
    CU_ASSERT_EQUAL(strcmp(actual, "valid"), 0);

    //	system under control
    length = 6;
    actual = makeString(&str[6], length);
    //	verify
    CU_ASSERT_EQUAL(strcmp(actual, "string"), 0);

    //	teardown (nothing)
}

void makeString_DonotMakeWithSameString(void)
{
    //	fixture setup
    char	str[] = "valid";
    int		length = 5;

    //	test
    char* first = makeString(str, length);
    char* second = makeString(str, length);

    //	verify
    CU_ASSERT_EQUAL(first, second);
}


/*-----------------                      ------------------------*/

void freeStrings_ShouldFree(void)
{
    //	fixture setup(already made by former tests)
    //	system under control
    freeStrings();
    //	verify
    for (StringChainPtr ptr = g_head; ptr; ptr = ptr->next)
	CU_ASSERT_EQUAL(ptr->str, NULL);
}





/*---------------------codes to make tests run-------------------*/

int main (int argc, char* argv[])
{
    if (CU_initialize_registry() != CUE_SUCCESS)
    {
	printf("attempt to initialize registry, failed!\n");
	exit(-1);
    }

    CU_pSuite suite = CU_add_suite("Suite----makeString", NULL, NULL);
    if (suite == NULL)
    {
	printf("attempt to add suite, failed!\n");
	CU_cleanup_registry();
	exit(-1);
    }

    //	add tests
    CU_TestInfo tests[] = {
	{ "test func-----makeString()", makeString_ShouldReturnNullOnInvalidParams },
	{ "test func----makeString()", makeString_ShouldReturnValidStringOnValidParam },
	{ "test func----makeString()", makeString_DonotMakeWithSameString },
	{ "freeStrings()", freeStrings_ShouldFree }
    };

    for (unsigned i = 0; i < (sizeof(tests) / sizeof(tests[0])); ++i)
	if (CU_add_test(suite, tests[i].pName, tests[i].pTestFunc) == NULL)
	{
	    printf("attempt to add test, failed!\n");
	    CU_cleanup_registry();
	    exit(-1);
	}

    if (CU_basic_run_suite(suite) != CUE_SUCCESS)
    {
	printf("attempt to run tests, failed!\n");
	CU_cleanup_registry();
	exit(-1);
    }

    CU_cleanup_registry();
    return 0;
}
