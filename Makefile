
# compiler goo
CC = gcc-4.9
CSTD = -std=c11
CFLAGS = -pedantic -Wall -Werror -g $(CSTD)

OBJ_DIR = obj/

math.o: math/math.c math/math.h
	$(CC) $(CFLAGS) math/math.c -c -o $(OBJ_DIR)$@

minunit.o: test/minunit.c test/minunit.h
	$(CC) $(CFLAGS) test/minunit.c -c -o $(OBJ_DIR)$@


.PHONY: test clean setup
setup:
	mkdir -p $(OBJ_DIR)

test: math.o minunit.o setup
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o -o test-runner

clean:
	rm -Rf $(OBJ_DIR) && rm test-runner
