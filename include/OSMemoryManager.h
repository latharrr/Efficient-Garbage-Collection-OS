#ifndef OS_MEMORY_MANAGER_H
#define OS_MEMORY_MANAGER_H

#include <vector>
#include "MemoryBlock.h"

class OSMemoryManager {
private:
    std::vector<MemoryBlock> memory;
    int nextId;

    int totalGcRuns;
    int totalReclaimed;

public:
    OSMemoryManager();

    void allocateMemory(int size);
    void releaseReference(int id);
    void garbageCollect();

    int getUsedMemory() const;
    void displayMemoryStatus() const;
    void displaySummary() const;
};

#endif   