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
        .v1 = {.x = 4.0f, .y = 5.0f, .z = 6.0f, .w = 7.0f},
        .v2 = {.x = 8.0f, .y = 9.0f, .z = 10.0f, .w = 11.0f},
        .v3 = {.x = 12.0f, .y = 13.0f, .z = 14.0f, .w = 15.0f}
    };


    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m00 == 0.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m01 == 1.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m02 == 2.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m03 == 3.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m04 == 4.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m05 == 5.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m06 == 6.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m07 == 7.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m08 == 8.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m09 == 9.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m10 == 10.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m11 == 11.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m12 == 12.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m13 == 13.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m14 == 14.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.m15 == 15.0f);

    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v0.x == 0.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v0.y == 1.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v0.z == 2.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v0.w == 3.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v1.x == 4.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v1.y == 5.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v1.z == 6.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v1.w == 7.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v2.x == 8.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v2.y == 9.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v2.z == 10.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v2.w == 11.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v3.x == 12.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v3.y == 13.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v3.z == 14.0f);
    mu_assert(get_msg("test_matrix_ctor", __LINE__, __FILE__), a.v3.w == 15.0f);

    return 0;
}

