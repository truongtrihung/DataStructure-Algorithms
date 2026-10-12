#include <iostream>
#include <vector>
using namespace std;

class DoubleHashTable {
    const int EMPTY = -1;
    const int DELETED = -2;
    int tableSize;
    int currentSize;
    vector<int> table;

public:
    DoubleHashTable(int n) : tableSize(n), currentSize(0) {
        table.assign(tableSize, EMPTY);
    }

    int hash1(int key) {
        return key % tableSize;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        if (currentSize == tableSize) {
            cout << "Table Full\n";
            return;
        }

        int index = hash1(key);

        if (table[index] != EMPTY && table[index] != DELETED) {
            int step = hash2(key);
            int i = 1;
            while (true) {
                int newIndex = (index + i * step) % tableSize;
                if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                    table[newIndex] = key;
                    break;
                }
                i++;
            }
        } else {
            table[index] = key;
        }
        currentSize++;
    }

    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % tableSize] != EMPTY) {
            if (table[(index + i * step) % tableSize] == key)
                return true;
            i++;
            if (i == tableSize) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] == EMPTY) cout << i << " -> EMPTY\n";
            else if (table[i] == DELETED) cout << i << " -> DELETED\n";
            else cout << i << " -> " << table[i] << "\n";
        }
    }
};

int main() {
    DoubleHashTable ht(11);
    int keys[] = {19, 27, 36, 10, 64};

    for (int k : keys) ht.insert(k);

    ht.display();
    cout << "Search 36: " << (ht.search(36) ? "Found" : "Not Found") << endl;
}