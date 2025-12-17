#include "../include/OSMemoryManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

static const int TOTAL_MEMORY = 4096;     // 4 KB
static const float GC_THRESHOLD = 0.75f; // Efficient GC trigger

OSMemoryManager::OSMemoryManager() {
    nextId = 1;
    totalGcRuns = 0;
    totalReclaimed = 0;
}

// ---------------- ALLOCATION ----------------
void OSMemoryManager::allocateMemory(int size) {

    if (size <= 0 || size > TOTAL_MEMORY) {
        cout << "[ERROR] Invalid memory request.\n";
        return;
    }

    if (getUsedMemory() + size > TOTAL_MEMORY) {
        cout << "[OS] Memory pressure detected. Running GC...\n";
        garbageCollect();
    }

    if (getUsedMemory() + size > TOTAL_MEMORY) {
        cout << "[ERROR] Allocation failed even after GC.\n";
        return;
    }

    // Reuse free block if possible (fragmentation reduction)
    for (auto &block : memory) {
        if (!block.allocated && block.size >= size) {
            block.id = nextId++;
            block.size = size;
            block.refCount = 1;
            block.allocated = true;
            cout << "[ALLOC] Reused block " << block.id << "\n";
            return;
        }
    }

    MemoryBlock block;
    block.id = nextId++;
    block.size = size;
    block.refCount = 1;
    block.allocated = true;

    memory.push_back(block);
    cout << "[ALLOC] Block " << block.id << " allocated (" << size << " bytes)\n";

    if (getUsedMemory() > TOTAL_MEMORY * GC_THRESHOLD) {
        cout << "[OS] High memory usage (>75%). Scheduling GC...\n";
        garbageCollect();
    }
}

// ---------------- RELEASE ----------------
void OSMemoryManager::releaseReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount = 0;
            cout << "[RELEASE] Process " << block.process << " terminated\n";
            return;
        }
    }
    cout << "[WARN] Invalid Block ID\n";
}

// ---------------- GARBAGE COLLECTION ----------------
void OSMemoryManager::garbageCollect() {
    totalGcRuns++;
    int reclaimed = 0;

    for (auto &block : memory) {
        if (block.allocated && block.refCount == 0) {
            reclaimed += block.size;
            block.allocated = false;
            block.process = "---";
        }
    }

    totalReclaimed += reclaimed;
    cout << "[GC] Reclaimed " << reclaimed << " bytes\n";
}

// ---------------- UTILITIES ----------------
int OSMemoryManager::getUsedMemory() const {
    int used = 0;
    for (const auto &block : memory)
        if (block.allocated) used += block.size;
    return used;
}

void OSMemoryManager::displayMemoryStatus() const {
    cout << "\n---------------- MEMORY STATUS ----------------\n";
    cout << left << setw(6) << "ID"
         << setw(15) << "Process"
         << setw(10) << "Size"
         << setw(10) << "State\n";

    for (const auto &block : memory) {
        cout << left << setw(6) << block.id
             << setw(15) << block.process
             << setw(10) << block.size
             << setw(10) << (block.allocated ? "USED" : "FREE") << "\n";
    }

    cout << "Used Memory: " << getUsedMemory()
         << " / " << TOTAL_MEMORY << " bytes\n";
}

void OSMemoryManager::displaySummary() const {
    cout << "\n===== SYSTEM SUMMARY =====\n";
    cout << "Total GC Runs       : " << totalGcRuns << "\n";
    cout << "Total Memory Freed  : " << totalReclaimed << " bytes\n";
}
