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
        struct Node* prev = NULL;
        // Insert in descending order of exponent
        while (ptr != NULL && ptr->exp > e) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr != NULL && ptr->exp == e) {
            ptr->coeff += c;
            free(temp);
        } else {
            if (prev == NULL) {
                temp->next = *poly;
                *poly = temp;
            } else {
                prev->next = temp;
                temp->next = ptr;
            }
        }
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

struct Node* multiplyPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    for (struct Node* ptr1 = p1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (struct Node* ptr2 = p2; ptr2 != NULL; ptr2 = ptr2->next) {
            int c = ptr1->coeff * ptr2->coeff;
            int e = ptr1->exp + ptr2->exp;
            insertTerm(&result, c, e);
        }
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 1, 0);

    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    display(product);

    return 0;
}
