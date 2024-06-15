// Question 1: Implement a Hash Map

// Implement a hash map (or hash table) data structure in C++. The hash map should support the following operations:

// put(key, value): Inserts a key-value pair into the hash map. If the key already exists, update the value.
// get(key): Returns the value associated with the key, or -1 if the key does not exist.
// remove(key): Removes the key-value pair from the hash map if it exists.


#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    static const int HASH_SIZE = 1000;
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % HASH_SIZE;
    }

public:
    MyHashMap() : table(HASH_SIZE) {}

    void put(int key, int value) {
        int index = hash(key);
        for (auto& p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);
        for (auto& p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove_if([key](const pair<int, int>& p) { return p.first == key; });
    }
};

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << "Value for key 1: " << hashMap.get(1) << endl; // Returns 1
    cout << "Value for key 3: " << hashMap.get(3) << endl; // Returns -1
    hashMap.put(2, 1);           // Update value for key 2
    cout << "Value for key 2: " << hashMap.get(2) << endl; // Returns 1
    hashMap.remove(2);           // Remove key 2
    cout << "Value for key 2: " << hashMap.get(2) << endl; // Returns -1

    return 0;
}


// Test Case 1: Basic Operations
    // Input: 
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl; // Expected Output: 1
    cout << hashMap.get(3) << endl; // Expected Output: -1

    // Output:
     1
    -1

// Test Case 2: Updating Value
    // Input: 
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    hashMap.put(2, 1);
    cout << hashMap.get(2) << endl; // Expected Output: 1

    // Output:
    1

// Test Case 3: Removing Key
    // Input: 
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    hashMap.remove(2);
    cout << hashMap.get(2) << endl; // Expected Output: -1

    // Output:
    -1


