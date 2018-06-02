
# compiler goo
CC = gcc-4.9
CSTD = -std=c11
CFLAGS = -pedantic -Wall -Werror -g $(CSTD)

OBJ_DIR = obj/
TMP_DIR = tmp/

TEST_EXEC = test-runner

math.o: math/math.c math/math.h
	$(CC) $(CFLAGS) math/math.c -c -o $(OBJ_DIR)$@

mathunit.o: math.o test/mathunit.c
	$(CC) $(CFLAGS) test/mathunit.c -c -o $(OBJ_DIR)$@

minunit.o: test/minunit.c test/minunit.h mathunit.o
	$(CC) $(CFLAGS) test/minunit.c -c -o $(OBJ_DIR)$@

.PHONY: test clean setup
setup:
	mkdir -p $(OBJ_DIR) $(TMP_DIR)

test: setup math.o minunit.o
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o -o $(TMP_DIR)$(TEST_EXEC)
	$(TMP_DIR)$(TEST_EXEC)

clean:
	rm -Rf $(OBJ_DIR) $(TMP_DIR)
