#include <stdio.h>

#define MAX 5

void printGraph(int graph[MAX][MAX]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph (undirected)
    int graph[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    printGraph(graph);
    return 0;
}
