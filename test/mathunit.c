#include <stdio.h>
#include "minunit.h"

#include "../math/math.h"

char ERROR_MSG_BUFFER[256u];

char *get_msg(const char *const name, int line, const char *const file)
{
    sprintf(ERROR_MSG_BUFFER, "(%s, %s, %d)\n", name, file, line);
    return ERROR_MSG_BUFFER;
}

char *test_dot() {

    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 4.0f, .z = 2.0f, .w = 1.0f};

    const float res = vec4f_dot(&a, &b);

    mu_assert(get_msg("test_dot", __LINE__, __FILE__), res == 8.0f);
    return 0;
}

char *test_add() {

    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

    const vec4f res = vec4f_add(&a, &b);

    mu_assert(get_msg("test_add", __LINE__, __FILE__), res.x == 1.0f);
    mu_assert(get_msg("test_add", __LINE__, __FILE__), res.y == 3.0f);
    mu_assert(get_msg("test_add", __LINE__, __FILE__), res.z == 5.0f);
    mu_assert(get_msg("test_add", __LINE__, __FILE__), res.w == 5.0f);

    return 0;
}

char *test_sub()
{
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 4.0f};

    const vec4f res = vec4f_sub(&a, &b);
 
    mu_assert(get_msg("test_sub", __LINE__, __FILE__), res.x == -1.0f);
    mu_assert(get_msg("test_sub", __LINE__, __FILE__), res.y == -1.0f);
    mu_assert(get_msg("test_sub", __LINE__, __FILE__), res.z == -1.0f);
    mu_assert(get_msg("test_sub", __LINE__, __FILE__), res.w == -3.0f);

    return 0;
}

char *test_mul_v(void)
{
    
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    vec4f b = {.x = 1.0f, .y = 2.0f, .z = 4.0f, .w = -4.0f};

    const vec4f res = vec4f_mul(&a, &b);

    mu_assert(get_msg("test_mul_v", __LINE__, __FILE__), res.x == 0.0f);
    mu_assert(get_msg("test_mul_v", __LINE__, __FILE__), res.y == 2.0f);
    mu_assert(get_msg("test_mul_v", __LINE__, __FILE__), res.z == 8.0f);
    mu_assert(get_msg("test_mul_v", __LINE__, __FILE__), res.w == -4.0f);

    return 0;
}

char *test_mul_s()
{
    vec4f a = {.x = 0.0f, .y = 1.0f, .z = 2.0f, .w = 1.0f};
    const float s = 4.0f;

    const vec4f res = vec4f_mul(s, &a);

    mu_assert(get_msg("test_mul_s", __LINE__, __FILE__), res.x == 0.0f);
    mu_assert(get_msg("test_mul_s", __LINE__, __FILE__), res.y == 4.0f);
    mu_assert(get_msg("test_mul_s", __LINE__, __FILE__), res.z == 8.0f);
    mu_assert(get_msg("test_mul_s", __LINE__, __FILE__), res.w == 4.0f);

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

