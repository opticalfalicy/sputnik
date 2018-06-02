#include <stdio.h>
#include "minunit.h"

int tests_passed = 0;

static char *all_tests() 
{

    mu_run_test(test_dot);
    mu_run_test(test_add);
    mu_run_test(test_sub);
    mu_run_test(test_mul_v);
    mu_run_test(test_mul_s);
    mu_run_test(test_mul_m);
    mu_run_test(test_matrix_ctor);

    mu_run_test(test_slink_add);

    return 0;
}

int main(int argc, char **argv) 
{
    const char *const result = all_tests();

    printf("\n\n== Unit Test Results ==\n\n");
    if (result != 0) {
        printf("FAILURE: %s\n\n\n", result);
    }

    printf("passed: %d\n\n\n", tests_passed);

    return result != 0;
}
