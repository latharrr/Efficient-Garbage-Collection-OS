#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>

struct MemoryBlock {
    int id;
    int size;
    int refCount;
    bool allocated;
};

class MemoryManager {
private:
    std::vector<MemoryBlock> memory;
    int nextId;

public:
    MemoryManager();
    void allocate(int size);
    void addReference(int id);
    void removeReference(int id);

    // UNIT V: Garbage Collection
    void garbageCollect();
};

#endif
