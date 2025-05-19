#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int size;
    int free;  // 1 if free, 0 if allocated
    struct Block* prev;
    struct Block* next;
} Block;

Block* head = NULL;

// Initialize memory blocks
void initialize(int sizes[], int n) {
    Block* temp;
    for (int i = 0; i < n; i++) {
        Block* newBlock = (Block*) malloc(sizeof(Block));
        newBlock->size = sizes[i];
        newBlock->free = 1;
        newBlock->prev = NULL;
        newBlock->next = NULL;

        if (head == NULL) {
            head = newBlock;
            temp = head;
        } else {
            temp->next = newBlock;
            newBlock->prev = temp;
            temp = newBlock;
        }
    }
}

// Allocate memory of given size
Block* allocate(int size) {
    Block* temp = head;
    while (temp != NULL) {
        if (temp->free && temp->size >= size) {
            temp->free = 0;
            printf("Allocated block of size %d\n", temp->size);
            return temp;
        }
        temp = temp->next;
    }
    printf("No suitable block found for size %d\n", size);
    return NULL;
}

// Free the given block
void freeBlock(Block* block) {
    block->free = 1;
    printf("Freed block of size %d\n", block->size);
}

// Display memory blocks
void display() {
    Block* temp = head;
    printf("Memory Blocks:\n");
    while (temp != NULL) {
        printf("Block size: %d, %s\n", temp->size, (temp->free) ? "Free" : "Allocated");
        temp = temp->next;
    }
}

int main() {
    int sizes[] = {100, 500, 200, 300, 600};
    int n = sizeof(sizes)/sizeof(sizes[0]);

    initialize(sizes, n);
    display();

    Block* b1 = allocate(200);
    Block* b2 = allocate(300);

    display();

    freeBlock(b1);

    display();

    return 0;
}
