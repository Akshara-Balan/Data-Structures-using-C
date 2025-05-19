#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("Pushed %d onto stack\n", value);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped %d from stack\n", stack[top]);
    top--;
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
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
