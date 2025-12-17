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

    std::cout << "Allocated memory block ID: "
              << block.id << " Size: " << block.size << std::endl;
}

void MemoryManager::addReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount++;
            std::cout << "Increased reference count of block "
                      << id << std::endl;
            return;
        }
    }
}

void MemoryManager::removeReference(int id) {
    for (auto &block : memory) {
        if (block.id == id && block.allocated) {
            block.refCount--;
            std::cout << "Decreased reference count of block "
                      << id << std::endl;
            return;
        }
    }
}

// 🔥 Garbage Collection Logic (Unit V)
void MemoryManager::garbageCollect() {
    std::cout << "\n[GC STARTED] Reclaiming unused memory...\n";

    for (auto &block : memory) {
        if (block.allocated && block.refCount == 0) {
            block.allocated = false;
            std::cout << "Garbage Collected Block ID: "
                      << block.id << std::endl;
        }
    }
}

int main() {
    MemoryManager manager;

    manager.allocate(100);
    manager.allocate(200);

    manager.addReference(1);
    manager.removeReference(2);   // refCount becomes 0

    manager.garbageCollect();     // GC invoked

    return 0;
}
