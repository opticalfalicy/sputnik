
# compiler goo
CC = gcc
CSTD = std=c11
CFLAGS = -pedantic -Wall

# directory structure
TEST_DIR = test/
TEST_SRCS = minunit.c
TEST_OBJS = $($(TEST_DIR)TEST_SRCS:.c=.o)

MATH_DIR = math/
MATH_SRCS = math.c
MATH_OBJS = $($(MATH_DIR)MATH_SRCS:.c=.o)

OBJ_DIR = obj/

math.o: math/math.c math/math.h
	$(CC) $(CFLAGS) $(MATH_DIR)$(MATH_SRCS) -c -o $(OBJ_DIR)$@

minunit.o: test/minunit.c test/minunit.h
	$(CC) $(CFLAGS) test/minunit.c -c -o $(OBJ_DIR)$@

.PHONY: test-runner
test-runner: $(OBJ_DIR)*.o
	$(CC) $(CFLAGS) $(OBJ_DIR)math.o $(OBJ_DIR)minunit.o -o $@ 

