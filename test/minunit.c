#include <stdio.h>
#include "minunit.h"

#include "../math/math.h"

#define _RUN_MATH_TESTS 1

int tests_run = 0;

static char *test_dot() {

	vec4f a = {.data.v = {0.0f, 1.0f, 2.0f, 1.0f}};
	vec4f b = {.data.v = {1.0f, 4.0f, 2.0f, 1.0f}};

	const float res = dot(a, b);

	mu_assert("error, dot(a, b) != 8.0f", res == 8.0);
	return 0;
}

static char *test_add() {

	vec4f a = {.data.v = {0.0f, 1.0f, 2.0f, 1.0f}};
	vec4f b = {.data.v = {1.0f, 2.0f, 3.0f, 4.0f}};

	const vec4f res = add(a, b);

	mu_assert("error, add(a, b) != {1.0f, 3.0f, 5.0f, 5.0f}", 
		res.data.v.x == 1.0f && 
		res.data.v.y == 3.0f && 
		res.data.v.z == 5.0f && 
		res.data.v.w == 5.0f);

	return 0;
}

static char *all_tests() {
	mu_run_test(test_dot);
	mu_run_test(test_add);
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
