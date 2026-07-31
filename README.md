# Operating System Coursework (ST5004CEM)

## Overview

This repository contains the implementation of four operating system coursework tasks developed in C. The project demonstrates concepts including process management, memory management, file system security, and network programming.

## Project Structure

```
Operating-System-ST5004CEM_Coursework/
│
├── task1_process_management/
├── task2_memory_management/
├── task3_file_security/
├── task4_network_ipc/
├── docs/
└── README.md
```

## Tasks

### Task 1 – Process Management and Threading
- Multithreading using POSIX threads
- Mutex synchronization
- Round-robin scheduler simulation
- Race condition demonstration
- Deadlock prevention

### Task 2 – Memory Management Simulation
- Paging system
- Configurable page size
- FIFO page replacement
- LRU page replacement
- Page fault analysis
- Hit and fault ratio calculation

### Task 3 – File System Operations and Security
- User authentication
- File creation, reading, writing and deletion
- File permission management
- File encryption and decryption
- Audit logging

### Task 4 – Network Programming and IPC
- TCP client-server communication
- Socket programming
- Concurrent client handling
- User authentication
- Error handling and connection management

## Requirements

- GCC
- POSIX Threads (pthread)
- Linux or Unix-based operating system

## Compilation

Each task contains its own `Makefile`.

Example:

```bash
cd task1_process_management
make
./task1
```

## Author

Operating Systems Coursework  
ST5004CEM
