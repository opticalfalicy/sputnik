#include <stdio.h>
#include "minunit.h"

#include "../math/math.h"

#define _RUN_MATH_TESTS 1

int tests_run = 0;

static char *test_dot() {

	vec4f a = {0.0f, 1.0f, 2.0f, 1.0f};
	vec4f b = {1.0f, 4.0f, 2.0f, 1.0f};

	const float res = dot(a, b);

	mu_assert("error, dot(a, b) != 8.0f", res == 8.0);
	return 0;
}

static char *all_tests() {
	mu_run_test(test_dot);
	return 0;
}

int main(int argc, char **argv) {

	const char *const result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	return result != 0;
}
