#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Enqueued %d into queue\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Dequeued %d from queue\n", queue[front]);
    front++;
}

// Peek operation
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", queue[front]);
}

// Display operation
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
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
