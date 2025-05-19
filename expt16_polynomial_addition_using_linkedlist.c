#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

void insertTerm(struct Node** poly, int c, int e) {
    struct Node* temp = createNode(c, e);
    if (*poly == NULL) {
        *poly = temp;
    } else {
        struct Node* ptr = *poly;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node **ptr = &result;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(ptr, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(ptr, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insertTerm(ptr, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        while (*ptr != NULL) ptr = &(*ptr)->next;
    }

    while (p1 != NULL) {
        insertTerm(ptr, p1->coeff, p1->exp);
        p1 = p1->next;
        while (*ptr != NULL) ptr = &(*ptr)->next;
    }

    while (p2 != NULL) {
        insertTerm(ptr, p2->coeff, p2->exp);
        p2 = p2->next;
        while (*ptr != NULL) ptr = &(*ptr)->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 5, 2);
    insertTerm(&poly2, 5, 3);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}
