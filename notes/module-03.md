# System calls

- `int fd = open(file_name, mode, permissions)`
    - opens a file and returns file descriptor
    - returns `-1` on error
    - defined in `fcntl.h`
    - modes:
        - `O_RDONLY` : read only mode
        - `O_WRONLY` : write only mode
        - `O_RDWR` : read + write mode
        - `O_CREAT` : create file if it doesn’t exist
        - `O_TRUNC` : truncate file to 0 size
        - `O_APPEND` : append at end of file

---

- `ssize_t read(fd, buf, count)`
    - reads up to `count` bytes from file descriptor into buffer
    - returns number of bytes read
    - returns `0` → end of file (EOF)
    - returns `-1` → error
    - does NOT null-terminate data

---

- `ssize_t write(fd, buf, count)`
    - writes `count` bytes to file descriptor
    - returns number of bytes written
    - returns `-1` on error
    - always use actual bytes returned by `read()`

---

- `int close(fd)`
    - closes file descriptor
    - returns `0` on success
    - returns `-1` on error
    - releases OS resources

---

# Error handling

- `void perror(const char *msg)`
    - prints error message based on `errno`
    - format: `msg: system_error`
    - should be called immediately after failure

---

- `char *strerror(errno)`
    - returns string description of error code
    - alternative to `perror`

---

# Process control

- `void exit(status)`
    - terminates program immediately
    - `0` → success
    - non-zero → failure

---

# File descriptor table

- `0` → stdin (standard input)
- `1` → stdout (standard output)
- `2` → stderr (standard error)
- `3+` → file descriptors returned by `open()`

---

# File copy pattern (classic)

- open source file with `O_RDONLY`
- open destination file with `O_WRONLY | O_CREAT | O_TRUNC`
- loop:
    - `read()` from source
    - `write()` to destination using returned byte count
- close both files


# Process APIs

- `fork()` 
    - creates a new child process 
    - returns -1 when error.
    - returns 0 in child process.
    - returns fd of child process in parent process

- `exec()`
    - replaces the current process's program image with a nwe executable and starts running that executable in the same process(same PID).
    - doesnt return anything
    - Decoding family of `exec()`
        - `l` = list => arguments are passed one by one
        - `v` = vector => Argumetnsts are passed as an array.
        - `p` = PATH search => OS searches directories in `$PATH`. Dont need to provide full path.
        - `e` = environment => Allow supplying a custom environment.
    