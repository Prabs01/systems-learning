# Learning Roadmap

This roadmap is designed for incremental learning with practical coding.

## Module 00: Environment and Tooling

- Install compiler toolchain and debuggers.
- Learn basic build commands.
- Verify Linux development workflow.

Deliverable:
- Build and run your first C program.

## Module 01: C Fundamentals for Systems

- Pointers, arrays, structs, and manual memory management.
- Header/source file separation.
- Error handling with return codes.

Deliverable:
- Utility library with tests.

## Module 02: Linux System Calls

- `open`, `read`, `write`, `close`.
- `fork`, `exec`, `wait` basics.
- Error handling with `errno`.

Deliverable:
- Minimal shell-like command runner.

## Module 03: Processes, Signals, and IPC

- Process lifecycle and states.
- Pipes and basic inter-process communication.
- Signal handling patterns.

Deliverable:
- Parent/child process coordinator.

## Module 04: Files, Memory, and I/O

- File descriptors and buffering.
- `mmap` and virtual memory basics.
- Performance-aware I/O choices.

Deliverable:
- File inspector and hex viewer.

## Module 05: Networking Fundamentals

- OSI vs TCP/IP practical view.
- IP addressing, ports, and routing basics.
- DNS and packet flow concepts.

Deliverable:
- Networking notes + packet capture walkthrough.

## Module 06: Sockets and Client/Server

- Socket lifecycle (create, bind, listen, accept, connect).
- TCP vs UDP trade-offs.
- Robust send/receive loops.

Deliverable:
- Echo server and client.

## Module 07: Concurrency and I/O Multiplexing

- Blocking vs non-blocking I/O.
- `select`, `poll`, and `epoll` concepts.
- Threaded vs event-driven servers.

Deliverable:
- Multi-client chat server.

## Module 08: Protocols and Observability

- Define simple wire protocol.
- Logging, metrics, and tracing basics.
- Debugging with `strace`, `ltrace`, `tcpdump`, `gdb`.

Deliverable:
- Protocol-based key/value server.

## Module 09: Projects

- Build capstone projects that combine systems and networking.
- Emphasize correctness, resilience, and debuggability.

Deliverable:
- Documented final project with benchmarks.
