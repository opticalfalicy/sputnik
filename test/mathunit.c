#include <stdio.h>
#include "minunit.h"

#include "../math/math.h"

char *test_dot() {

    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 4.0f, .z = 2.0f, .w = 1.0f};

    const float res = vec4f_dot(&a, &b);

    mu_assert("error, dot(a, b) != 8.0f", res == 8.0);
    return 0;
}

char *test_add() {

    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

    const vec4f res = vec4f_add(&a, &b);

    mu_assert("error, add(a, b) != {1.0f, 3.0f, 5.0f, 5.0f}", 
        res.x == 1.0f && 
        res.y == 3.0f && 
        res.z == 5.0f && 
        res.w == 5.0f);

    return 0;
}

char *test_sub()
{
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

    const vec4f res = vec4f_sub(&a, &b);

    mu_assert("x != -1.0", res.x == -1.0f);
    mu_assert("y != -1.0", res.y == -1.0f);
    mu_assert("z != -1.0", res.z == -1.0f);
    mu_assert("w != -3.0", res.w == -3.0f);

    return 0;
}

char *test_mul_v(void)
{
    
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 4.0f, .w = -4.0f};

    const vec4f res = vec4f_mul(&a, &b);

    mu_assert("x != 0.0", res.x == 0.0f);
    mu_assert("y != 2.0", res.y == 2.0f);
    mu_assert("z != 8.0", res.z == 8.0f);
    mu_assert("w != -4.0", res.w == -4.0f);

    return 0;
}

char *test_mul_s()
{
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    const float s = 4.0f;

    const vec4f res = vec4f_mul(s, &a);

    mu_assert("x != 0.0", res.x == 0.0f);
    mu_assert("y != 4.0", res.y == 4.0f);
    mu_assert("z != 8.0", res.z == 8.0f);
    mu_assert("w != 4.0", res.w == 4.0f);

    return 0;
}

char *test_matrix_ctor()
{
    matrix4f a = {
        .v0 = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 3.0f},
        .v1 = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 3.0f},
        .v2 = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 3.0f},
        .v3 = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 3.0f}
    };

    mu_assert("m15 != 3.0", a.m15 == 3.0f);

    return 0;
}
