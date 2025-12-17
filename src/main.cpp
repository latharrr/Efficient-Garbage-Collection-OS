#include "../include/memory_manager.h"
#include <iostream>

MemoryManager::MemoryManager() {
    nextId = 1;
}

void MemoryManager::allocate(int size) {
    MemoryBlock block;
    block.id = nextId++;
    block.size = size;
    block.allocated = true;

    memory.push_back(block);

    std::cout << "Allocated memory block ID: "
              << block.id << " Size: " << block.size << std::endl;
}

int main() {
    MemoryManager manager;

    manager.allocate(100);
    manager.allocate(200);

    return 0;
}
