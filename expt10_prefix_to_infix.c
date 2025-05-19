#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    }
}

void pop(char *str) {
    if (top == -1) {
        str[0] = '\0';
        return;
    }
    strcpy(str, stack[top--]);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void prefixToInfix(char *prefix, char *infix) {
    int len = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];
    top = -1;

    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(operand);
        } else if (isOperator(prefix[i])) {
            pop(op1);
            pop(op2);
            sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);
            push(temp);
        }
    }
    pop(infix);
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter prefix expression: ");
    gets(prefix);

    prefixToInfix(prefix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
