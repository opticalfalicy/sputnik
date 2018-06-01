#include <stdio.h>
#include "minunit.h"

#include "../math/math.h"

#define _RUN_MATH_TESTS 1

int tests_run = 0;

static char *test_dot() {

	vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
	vec4f b = {.x = 1.0f, .y = 4.0f, .z = 2.0f, .w = 1.0f};

	const float res = dot(&a, &b);

	mu_assert("error, dot(a, b) != 8.0f", res == 8.0);
	return 0;
}

static char *test_add() {

	vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
	vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

	const vec4f res = add(&a, &b);

	mu_assert("error, add(a, b) != {1.0f, 3.0f, 5.0f, 5.0f}", 
		res.x == 1.0f && 
		res.y == 3.0f && 
		res.z == 5.0f && 
		res.w == 5.0f);

	return 0;
}

static char *test_sub()
{
	vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
	vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

	const vec4f res = sub(&a, &b);

	mu_assert("x != -1.0", res.x == -1.0f);
	mu_assert("y != -1.0", res.y == -1.0f);
	mu_assert("z != -1.0", res.z == -1.0f);
	mu_assert("w != -3.0", res.w == -3.0f);

	return 0;
}

static char *all_tests() {
	mu_run_test(test_dot);
	mu_run_test(test_add);
	mu_run_test(test_sub);
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
