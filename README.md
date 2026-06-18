# Systems + Networking Learning Repo

A step-by-step, hands-on repository for learning systems programming and networking from fundamentals to real projects.

## Goals

- Build a strong C and Linux systems foundation.
- Learn how operating systems expose resources through system calls.
- Understand process, memory, file, and I/O primitives.
- Progress into networking with sockets and protocol design.
- Implement small projects that combine all concepts.

## Learning Flow

1. Environment + tooling
2. C language fundamentals
3. Linux system calls
4. Processes, signals, and IPC
5. Files, memory, and low-level I/O
6. Networking fundamentals
7. Sockets and client/server design
8. Concurrency and I/O multiplexing
9. Protocols, debugging, and observability
10. End-to-end systems projects

Detailed plan: see `docs/roadmap.md`

## Repository Structure

- `modules/` : Topic-by-topic study guides and checkpoints.
- `exercises/` : Small focused coding tasks.
- `projects/` : Larger milestone projects.
- `notes/` : Personal notes while learning.

## Quick Start

```bash
git status
make help
make hello
./exercises/build/hello
```

## Recommended Setup

- Linux (native preferred)
- GCC or Clang
- Make
- gdb
- strace
- tcpdump or Wireshark

## Progress Habit

For each module:

1. Read and summarize in `notes/`.
2. Complete exercises.
3. Build one mini artifact.
4. Write what was confusing and what clicked.
