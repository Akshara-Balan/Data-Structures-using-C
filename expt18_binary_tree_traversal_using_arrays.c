#include <stdio.h>

#define MAX 100

int tree[MAX];  // Array representation of binary tree
int n;  // Number of elements in the tree

void inorder(int i) {
    if (i >= n || tree[i] == -1)
        return;
    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

void preorder(int i) {
    if (i >= n || tree[i] == -1)
        return;
    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

void postorder(int i) {
    if (i >= n || tree[i] == -1)
        return;
    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6
    // Use -1 to represent NULL nodes in array

    int i;
    int example[] = {1, 2, 3, 4, 5, -1, 6};
    n = 7;
    for (i = 0; i < n; i++) {
        tree[i] = example[i];
    }

    printf("Inorder traversal: ");
    inorder(0);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(0);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(0);
    printf("\n");

    return 0;
}
