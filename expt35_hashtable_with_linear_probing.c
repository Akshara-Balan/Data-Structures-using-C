#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

// Insert key using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash Table full, cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

// Search key in hash table
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
            return -1;
    }
    return -1;
}

// Display hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d]: EMPTY\n", i);
        else
            printf("[%d]: %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    int key = 30;
    int idx = search(key);
    if (idx != -1)
        printf("Key %d found at index %d\n", key, idx);
    else
        printf("Key %d not found\n", key);

    return 0;
}
