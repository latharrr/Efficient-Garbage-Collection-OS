#include "../include/OSMemoryManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int TOTAL_MEMORY = 1024;      // Simulated main memory
const float GC_THRESHOLD = 0.70f;   // Demand-based GC trigger

OSMemoryManager::OSMemoryManager() {
    nextId = 1;
}

// Allocate memory to a process
void OSMemoryManager::allocateMemory(int size) {
    MemoryBlock block;
    block.id = nextId++;
    block.size = size;
    block.refCount = 1;
    block.allocated = true;

    memory.push_back(block);

    cout << "[ALLOC] Block ID " << block.id
         << " allocated (" << size << " bytes)\n";

    // Demand-based garbage collection
    if (getUsedMemory() > TOTAL_MEMORY * GC_THRESHOLD) {
        cout << "\n[OS] High memory usage detected. Triggering GC...\n";
        garbageCollect();
    }
}

// Simulate process releasing memory
void OSMemoryManager::releaseReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount--;
            cout << "[RELEASE] Reference removed from Block ID "
                 << id << "\n";
            return;
        }
    }
}

// Reference-count based garbage collection
void OSMemoryManager::garbageCollect() {
    cout << "[GC] Garbage Collection Started\n";
    for (auto &block : memory) {
        if (block.allocated && block.refCount == 0) {
            block.allocated = false;
            cout << "[GC] Block ID " << block.id
                 << " reclaimed\n";
        }
    }
    cout << "[GC] Garbage Collection Completed\n\n";
}

// Calculate used memory
int OSMemoryManager::getUsedMemory() {
    int used = 0;
    for (auto &block : memory) {
        if (block.allocated)
            used += block.size;
    }
    return used;
}

// Display memory table
void OSMemoryManager::displayMemoryStatus() {
    cout << "\n---------------- MEMORY STATUS ----------------\n";
    cout << left << setw(10) << "BlockID"
         << setw(10) << "Size"
         << setw(12) << "RefCount"
         << setw(10) << "State" << "\n";

    for (auto &block : memory) {
        cout << left << setw(10) << block.id
             << setw(10) << block.size
             << setw(12) << block.refCount
             << setw(10)
             << (block.allocated ? "USED" : "FREE") << "\n";
    }

    cout << "Total Used Memory: "
         << getUsedMemory() << " / "
         << TOTAL_MEMORY << " bytes\n";
}
