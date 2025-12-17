#include "../include/memory_manager.h"
#include <iostream>

MemoryManager::MemoryManager() {
    nextId = 1;
}

void MemoryManager::allocate(int size) {
    MemoryBlock block;
    block.id = nextId++;
    block.size = size;
    block.refCount = 1;
    block.allocated = true;

    memory.push_back(block);

    std::cout << "Allocated Block ID: "
              << block.id << " Size: " << block.size << std::endl;
}

void MemoryManager::addReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount++;
            return;
        }
    }
}

void MemoryManager::removeReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount--;
            return;
        }
    }
}

void MemoryManager::garbageCollect() {
    std::cout << "\n[GC STARTED]\n";
    for (auto &block : memory) {
        if (block.allocated && block.refCount == 0) {
            block.allocated = false;
            std::cout << "Reclaimed Block ID: " << block.id << std::endl;
        }
    }
}

int MemoryManager::totalUsedMemory() {
    int total = 0;
    for (auto &block : memory) {
        if (block.allocated)
            total += block.size;
    }
    return total;
}

void MemoryManager::showMemoryStatus() {
    std::cout << "\n--- MEMORY STATUS ---\n";
    for (auto &block : memory) {
        std::cout << "ID: " << block.id
                  << " Size: " << block.size
                  << " RefCount: " << block.refCount
                  << " Allocated: " << block.allocated
                  << std::endl;
    }
}

int main() {
    MemoryManager manager;

    manager.allocate(100);
    manager.allocate(200);
    manager.allocate(300);

    manager.removeReference(2);   // make block eligible for GC

    manager.showMemoryStatus();

    // 🔥 Demand-based GC trigger
    if (manager.totalUsedMemory() > 400) {
        manager.garbageCollect();
    }

    manager.showMemoryStatus();

    return 0;
}
