#include "../include/memory_manager.h"
#include <iostream>

MemoryManager::MemoryManager() {
    nextId = 1;
}

void MemoryManager::allocate(int size) {
    MemoryBlock block;
    block.id = nextId++;
    block.size = size;
    block.refCount = 1;   // Initial reference
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

int main() {
    MemoryManager manager;

    manager.allocate(100);
    manager.allocate(200);

    manager.addReference(1);
    manager.removeReference(2);

    return 0;
}
