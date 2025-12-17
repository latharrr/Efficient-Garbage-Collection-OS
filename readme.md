# Efficient Garbage Collection in Operating Systems

This project simulates OS-level memory management using an efficient
reference-count-based garbage collection mechanism.

## Features
- Contiguous memory allocation
- Process termination & memory release
- Demand-based garbage collection
- Fragment reuse to reduce memory wastage
- Interactive menu-driven simulation
- Efficient GC triggering based on threshold
- Displays current memory usage table

## How to Compile and Run
```bash
g++ -I./include src/main.cpp src/OSMemoryManager.cpp -o program.exe
.\program.exe    # Windows
./program        # Linux/Mac
```

## Syllabus Mapping
This project aligns with Memory Management (CSE316):
- Unit I: OS responsibilities
- Unit II: Process load simulation
- Unit III: Critical section (conceptual)
- Unit IV: Memory starvation prevention
- Unit V: Memory allocation & reclamation
