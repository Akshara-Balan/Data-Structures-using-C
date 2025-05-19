#include <stdio.h>

#define MAX_TERMS 100

int main() {
    int poly1[MAX_TERMS][2], poly2[MAX_TERMS][2], result[MAX_TERMS][2];
    int n1, n2, n3 = 0;
    int i = 0, j = 0;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coefficient and exponent in descending order):\n");
    for (i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i][0], &poly1[i][1]); // coeff, expo
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coefficient and exponent in descending order):\n");
    for (i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i][0], &poly2[i][1]); // coeff, expo
    }

    i = 0; j = 0;
    while (i < n1 && j < n2) {
        if (poly1[i][1] == poly2[j][1]) {
            result[n3][0] = poly1[i][0] + poly2[j][0];
            result[n3][1] = poly1[i][1];
            i++; j++;
        } else if (poly1[i][1] > poly2[j][1]) {
            result[n3][0] = poly1[i][0];
            result[n3][1] = poly1[i][1];
            i++;
        } else {
            result[n3][0] = poly2[j][0];
            result[n3][1] = poly2[j][1];
            j++;
        }
        n3++;
    }

    // Remaining terms
    while (i < n1) {
        result[n3][0] = poly1[i][0];
        result[n3][1] = poly1[i][1];
        i++; n3++;
    }
    while (j < n2) {
        result[n3][0] = poly2[j][0];
        result[n3][1] = poly2[j][1];
        j++; n3++;
    }

    // Display result
    printf("Resultant Polynomial: ");
    for (i = 0; i < n3; i++) {
        printf("%dx^%d", result[i][0], result[i][1]);
        if (i != n3 - 1) printf(" + ");
    }
    printf("\n");

    return 0;
}
