#include <stdio.h>
#define MAX 100

int queue[MAX];
int priority[MAX];
int size = 0;

// Insert element according to priority
void enqueue(int value, int prio) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;
    // Move elements with lower priority to the right
    while (i >= 0 && priority[i] > prio) {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }
    queue[i + 1] = value;
    priority[i + 1] = prio;
    size++;
    printf("Inserted %d with priority %d\n", value, prio);
}

// Remove highest priority element
void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d with priority %d\n", queue[0], priority[0]);

    // Shift left all elements
    for (int i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
        priority[i - 1] = priority[i];
    }
    size--;
}

// Display queue elements
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue:\n");
    printf("Value\tPriority\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%d\n", queue[i], priority[i]);
}

int main() {
    int choice, value, prio;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter priority (lower number = higher priority): ");
            scanf("%d", &prio);
            enqueue(value, prio);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
