#include "../include/OSMemoryManager.h"
#include <iostream>

using namespace std;

int main() {
    OSMemoryManager os;
    int choice;

    while (true) {
        cout << "\n===== OS MEMORY MANAGEMENT MENU =====\n";
        cout << "1. Allocate Memory\n";
        cout << "2. Terminate Process\n";
        cout << "3. Run Garbage Collection\n";
        cout << "4. Display Memory Status\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int size;
            cout << "Memory Size (bytes): ";
            cin >> size;
            os.allocateMemory(size);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter Block ID: ";
            cin >> id;
            os.releaseReference(id);
        }
        else if (choice == 3) {
            os.garbageCollect();
        }
        else if (choice == 4) {
            os.displayMemoryStatus();
        }
        else if (choice == 5) {
            os.displaySummary();
            break;
        }
    }

    return 0;
}
