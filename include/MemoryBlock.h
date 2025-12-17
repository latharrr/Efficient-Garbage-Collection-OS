#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

struct MemoryBlock {
    int id;
    int size;
    int refCount;
    bool allocated;
};

#endif
