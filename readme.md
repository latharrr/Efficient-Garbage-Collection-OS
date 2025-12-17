# Efficient Garbage Collection in Operating Systems

This project simulates OS-level memory management using an efficient
reference-count-based garbage collection mechanism.

## Features
- Contiguous memory allocation
- Process termination & memory release
- Demand-based garbage collection
- Fragment reuse to reduce memory wastage
- Interactive menu-driven simulation

## Compile & Run
g++ src/main.cpp src/OSMemoryManager.cpp -o gc
./gc   (Linux/Mac)
gc.exe (Windows)

## Syllabus Mapping
- Unit I: OS responsibilities
- Unit II: Process load simulation
- Unit III: Critical section (conceptual)
- Unit IV: Memory starvation prevention
- Unit V: Memory allocation & reclamation
