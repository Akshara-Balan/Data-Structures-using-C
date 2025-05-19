#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1)
        stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int evaluatePostfix(char *postfix) {
    int i = 0;
    char c;
    int op1, op2;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            push(c - '0');  // convert char to int
        } else {
            op2 = pop();
            op1 = pop();
            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single digit operands): ");
    gets(postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
