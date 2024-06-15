// Question 2: Implement a Hash Set

// Implement a hash set data structure in C++. The hash set should support the following operations:

// add(value): Adds a value to the hash set. If the value already exists, do nothing.
// contains(value): Returns true if the value exists in the hash set, and false otherwise.
// remove(value): Removes the value from the hash set if it exists.

#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    static const int HASH_SIZE = 1000;
    vector<list<int>> table;

    int hash(int key) {
        return key % HASH_SIZE;
    }

public:
    MyHashSet() : table(HASH_SIZE) {}

    void add(int key) {
        int index = hash(key);
        for (int& k : table[index]) {
            if (k == key) {
                return;
            }
        }
        table[index].push_back(key);
    }

    bool contains(int key) {
        int index = hash(key);
        for (int& k : table[index]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key);
    }
};

int main() {
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout << "Contains 1: " << hashSet.contains(1) << endl; // Returns true
    cout << "Contains 3: " << hashSet.contains(3) << endl; // Returns false
    hashSet.add(2);
    cout << "Contains 2: " << hashSet.contains(2) << endl; // Returns true
    hashSet.remove(2);
    cout << "Contains 2: " << hashSet.contains(2) << endl; // Returns false

    return 0;
}

// Test Case 1: Basic Operations
    // Input
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout << hashSet.contains(1) << endl; // Expected Output: true
    cout << hashSet.contains(3) << endl; // Expected Output: false

    // Output
    // 1
    // 0

// Test Case 2: Adding Duplicate Value
    // Input
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    hashSet.add(2);
    cout << hashSet.contains(2) << endl; // Expected Output: true
    cout << hashSet.contains(3) << endl; // Expected Output: false

    // Output
    // 1
    // 0

// Test Case 3: Removing Value
    // Input
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    hashSet.remove(2);
    cout << hashSet.contains(2) << endl; // Expected Output: false
    cout << hashSet.contains(3) << endl; // Expected Output: false

    // Output
    // 0
    // 0



