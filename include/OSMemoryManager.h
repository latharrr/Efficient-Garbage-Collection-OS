#ifndef OS_MEMORY_MANAGER_H
#define OS_MEMORY_MANAGER_H

#include <vector>
#include "MemoryBlock.h"

class OSMemoryManager {
private:
    std::vector<MemoryBlock> memory;
    int nextId;

public:
    OSMemoryManager();

    void allocateMemory(int size);     // User → OS request
    void releaseReference(int id);     // Process termination
    void garbageCollect();             // Memory reclamation

    int getUsedMemory();
    void displayMemoryStatus();
};

#endif
