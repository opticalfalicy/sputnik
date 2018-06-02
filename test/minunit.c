#include <stdio.h>
#include "minunit.h"

int tests_passed = 0;
int tests_failed = 0;

static char *all_tests() 
{


    mu_run_test(test_dot);
    mu_run_test(test_add);
    mu_run_test(test_sub);
    mu_run_test(test_mul_v);
    mu_run_test(test_mul_s);
    mu_run_test(test_matrix_ctor);


    return 0;
}

int main(int argc, char **argv) 
{
    const char *const result = all_tests();

    printf("\n\n== Unit Test Results ==\n\n");
    if (result != 0) {
        printf("FAILURE: %s\n\n\n", result);
    }

    printf("passed: %d\n", tests_passed);
    printf("failed: %d\n", tests_failed);
    printf("total: %d\n", tests_passed + tests_failed);

    return result != 0;
}
