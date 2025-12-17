# Efficient Garbage Collection in Operating Systems

This project simulates basic memory management in an operating system using C++.
It serves as the foundation for implementing efficient garbage collection
techniques as part of OS memory management.

Course: CSE316 – Operating Systems


## Syllabus Mapping
This project aligns with (Memory Management) of CSE316.
It demonstrates memory allocation, fragmentation, and garbage collection
for efficient memory utilization.

## How to Compile
g++ src/main.cpp src/OSMemoryManager.cpp -o gc
.\gc.exe    # (Windows)

## Features
- Allocate memory blocks dynamically
- Delete memory blocks via reference count decrement
- Efficient GC triggering based on threshold
- Displays current memory usage table
