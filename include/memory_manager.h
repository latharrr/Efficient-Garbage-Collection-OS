#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

class MemoryManager {
private:
    std::vector<MemoryBlock> memory;
    int nextId;

public:
    MemoryManager();
    void allocate(int size);
};

#endif
