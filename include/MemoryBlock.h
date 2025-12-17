#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

#include <string>

// Represents a contiguous block of memory allocated to a process
struct MemoryBlock {
    int id;                 // Unique block ID
    int size;               // Size in bytes
    int refCount;           // Reference count
    bool allocated;         // Allocation status
    std::string process;    // Process name
};

#endif
