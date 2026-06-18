CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -O0 -g

.PHONY: help hello clean

help:
	@echo "Available targets:"
	@echo "  make hello  - build first systems exercise"
	@echo "  make clean  - remove built binaries"

hello:
	$(CC) $(CFLAGS) exercises/01-hello-system/main.c -o exercises/01-hello-system/hello

clean:
	rm -f exercises/01-hello-system/hello
