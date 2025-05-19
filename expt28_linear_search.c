#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Return index if found
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 1;

    int result = linearSearch(arr, n, key);
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}
