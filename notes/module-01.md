# Memory management

- `void *malloc(size_t size)`
    - allocates memory on heap
    - returns pointer to allocated memory
    - returns `NULL` on failure
    - memory is uninitialized

---

- `void *realloc(ptr, new_size)`
    - resizes previously allocated memory
    - may move memory to a new location
    - returns new pointer or `NULL`
    - original pointer must not be lost on failure

---

- `void free(ptr)`
    - frees heap memory
    - prevents memory leaks

---