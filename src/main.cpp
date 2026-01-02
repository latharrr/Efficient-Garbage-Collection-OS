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
        cout << "Choice: ";

        if (!(cin >> choice)) {
             cout << "[ERROR] Invalid input. Enter numbers only (1-5).\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
}

if (choice < 1 || choice > 5) {
    cout << "[ERROR] Invalid menu option. Choose between 1 and 5.\n";
    continue;
}


        if (choice == 1) {
            int size;
cout << "Memory Size (bytes): ";

if (!(cin >> size)) {
    cout << "[ERROR] Invalid input. Enter numbers only.\n";
    cin.clear(); // clear fail state
    cin.ignore(10000, '\n'); // discard bad input
    continue;
}

if (size <= 0 || size > 4000) {
    cout << "[ERROR] Memory size must be between 1 and 4000 bytes.\n";
    continue;
}

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
