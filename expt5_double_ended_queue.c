#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
