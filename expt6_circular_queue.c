#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow (Full)\n");
        return;
    }

    if (front == -1) // Empty queue
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow (Empty)\n");
        return;
    }

    printf("Dequeued %d\n", queue[front]);

    if (front == rear) // Only one element
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// Peek operation
void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

// Display operation
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
