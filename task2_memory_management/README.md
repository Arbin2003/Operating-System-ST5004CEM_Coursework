# Task 2 – Memory Management

## Overview

This task demonstrates memory management concepts used by operating systems through a paging simulation implemented in Python. The project focuses on how pages are loaded into memory frames and how page replacement algorithms are used when memory becomes full. Two commonly used algorithms, First-In First-Out (FIFO) and Least Recently Used (LRU), were implemented and compared.

## Implementation

The memory management system simulates a fixed number of page frames. A sequence of page references is processed one by one. Whenever a page is requested, the program first checks whether the page already exists in memory.

If the page is already present, it is counted as a page hit. If the page is not present, it is counted as a page fault and the page must be loaded into memory.

The FIFO page replacement algorithm removes the oldest page currently stored in memory whenever all frames are occupied. This algorithm is simple because pages are replaced in the same order they entered memory.

The LRU page replacement algorithm replaces the page that has not been used for the longest period of time. This method attempts to keep frequently accessed pages in memory, which generally reduces the number of page faults.

During execution, the program displays the contents of memory after each page reference. It also records page hits, page faults, and calculates the hit ratio and fault ratio after processing the complete reference string.

## Testing

The program was tested using different page reference strings while keeping the number of memory frames fixed.

Both FIFO and LRU algorithms were executed using the same input to compare their behaviour fairly. The output was checked after each page request to verify that pages were inserted and replaced correctly.

The page hit and page fault counters were also verified to ensure that the final statistics matched the observed execution sequence.

## Results

The implementation successfully simulated virtual memory paging and demonstrated how different page replacement algorithms affect system performance.

FIFO correctly replaced the oldest pages whenever memory became full. LRU produced fewer page faults for many test cases because recently accessed pages remained in memory.

The displayed statistics made it easy to compare both algorithms and understand their efficiency.

## Conclusion

This task provided practical experience with memory management techniques used in modern operating systems. Implementing FIFO and LRU improved understanding of virtual memory, page replacement, page hits, and page faults. The comparison showed how different replacement strategies influence overall system performance and memory utilisation.
