#define mu_assert(message, test) do {if (!(test)) return message; } while(0)
#define mu_run_test(test) do { char *message = test(); \
				if (message) {++tests_failed; return message;} else {++tests_passed;}} while (0)

extern int tests_failed;
extern int tests_passed;

extern char *test_mul_v(void);
extern char *test_mul_s(void);
extern char *test_add(void);
extern char *test_sub(void);
extern char *test_dot(void);
extern char *test_matrix_ctor(void);
