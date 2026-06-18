CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -O0 -g

.PHONY: help hello clean

help:
	@echo "Available targets:"
	@echo "  make hello  - build first systems exercise"
	@echo "  make clean  - remove built binaries"

hello:
	$(CC) $(CFLAGS) exercises/01-hello-system/main.c -o exercises/build/hello

type:
	$(CC) $(CFLAGS) exercises/02-type-inspect/main.c -o exercises/build/type

integer_overflow:
	$(CC) $(CFLAGS) exercises/02-integer-overflow/main.c -o exercises/build/integer_overflow


dynamic_array:
	$(CC) $(CFLAGS) exercises/02-dynamic-array/main.c -o exercises/build/dynamic_array

file_copy:
	$(CC) $(CFLAGS) exercises/03-file-copy/main.c -o exercises/build/file_copy

clean:
	rm -f exercises/01-hello-system/hello
