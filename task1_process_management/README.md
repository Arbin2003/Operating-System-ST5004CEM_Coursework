# Task 1 – Process Management and Threading

## Overview

This task demonstrates important operating system concepts related to process management and multithreading using Python. The objective was to understand how multiple threads execute concurrently, how shared resources are protected using synchronization mechanisms, how CPU scheduling works, and how deadlocks can be prevented. The implementation provides practical examples of these concepts through simple Python programs.

## Implementation

The first part of the task creates three worker threads using Python's `threading` module. Each thread performs a fixed number of operations on a shared counter. Since multiple threads access the same variable, a `Lock` object is used to ensure that only one thread updates the counter at a time. This synchronization mechanism prevents race conditions and guarantees that the final counter value is correct after all threads have completed execution.

The project also includes a Round Robin scheduling simulation. Several processes are assigned burst times and executed using a fixed time quantum. Each process receives CPU time in turn until its remaining burst time becomes zero. This simulation demonstrates fairness in CPU scheduling because every process receives an equal opportunity to execute before another process receives additional CPU time.

Another part of the implementation demonstrates a race condition. A shared variable is updated by multiple threads without synchronization. The output illustrates how incorrect results can occur when multiple threads modify shared data simultaneously. The corrected version uses a mutex lock to protect the critical section, producing the expected result consistently.

The final component demonstrates deadlock prevention. Two threads require access to multiple shared resources. Instead of allowing resources to be acquired in an unsafe order, locks are obtained in a consistent sequence. This prevents circular waiting and avoids deadlock while allowing both threads to complete successfully.

## Testing

Each program was executed multiple times using Python 3 on Ubuntu Linux.

The multithreading program was tested to verify that all threads completed successfully and that the final counter value matched the expected result. The synchronization mechanism consistently prevented incorrect updates.

The Round Robin scheduler was tested using different process burst times. The execution order confirmed that each process received CPU time according to the selected time quantum until completion.

The race condition example was executed with and without synchronization. Without a lock, inconsistent counter values could occur. After introducing the mutex lock, the output became stable and correct.

The deadlock prevention program was tested to ensure that both threads completed execution without becoming permanently blocked while accessing shared resources.

## Results

The implementation successfully demonstrated the main concepts of process management and multithreading. Thread synchronization protected shared resources, the Round Robin scheduler illustrated fair CPU allocation, the race condition example showed the importance of synchronization, and the deadlock prevention technique ensured safe resource allocation. All programs executed correctly and produced the expected output.

## Conclusion

This task provided practical experience with operating system concepts including thread creation, synchronization, CPU scheduling, race conditions, and deadlock prevention. Implementing these techniques in Python improved understanding of how operating systems coordinate concurrent execution while maintaining correctness and system stability.
