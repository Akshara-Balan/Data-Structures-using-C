#include <stdio.h>

#define MAX 100

void readSparse(int sparse[][3], int *t) {
    int rows, cols, val;
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d%d%d", &sparse[0][0], &sparse[0][1], t);
    sparse[0][2] = *t;

    for (int i = 1; i <= *t; i++) {
        printf("Enter row, column, value for element %d: ", i);
        scanf("%d%d%d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }
}

void displaySparse(int sparse[][3]) {
    int t = sparse[0][2];
    printf("Row Col Val\n");
    for (int i = 0; i <= t; i++)
        printf("%3d %3d %3d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

void addSparse(int a[][3], int b[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;
    result[0][0] = a[0][0]; // rows
    result[0][1] = a[0][1]; // columns

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
        else if ((a[i][0] < b[j][0]) || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        } else {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
    }

    // Copy remaining elements
    while (i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1; // total non-zero terms
}

int main() {
    int A[MAX][3], B[MAX][3], Sum[MAX][3];
    int t1, t2;

    printf("Enter first sparse matrix:\n");
    readSparse(A, &t1);

    printf("Enter second sparse matrix:\n");
    readSparse(B, &t2);

    // Check dimensions
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Matrices cannot be added due to different dimensions.\n");
        return 1;
    }

    printf("\nFirst Sparse Matrix:\n");
    displaySparse(A);

    printf("\nSecond Sparse Matrix:\n");
    displaySparse(B);

    addSparse(A, B, Sum);

    printf("\nSum of Sparse Matrices:\n");
    displaySparse(Sum);

    return 0;
}
