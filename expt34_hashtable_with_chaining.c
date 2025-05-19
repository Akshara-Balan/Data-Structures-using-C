#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key into hash table
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Search key in hash table
Node* search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Display hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);
    insert(15);

    display();

    int key = 25;
    Node* found = search(key);
    if (found)
        printf("Key %d found in hash table.\n", key);
    else
        printf("Key %d not found.\n", key);

    return 0;
}
