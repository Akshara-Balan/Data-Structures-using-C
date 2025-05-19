#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void DFSUtil(Node* adjList[], int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    Node* temp = adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
            DFSUtil(adjList, adjVertex, visited);
        temp = temp->next;
    }
}

void DFS(Node* adjList[], int startVertex) {
    int visited[MAX] = {0};
    DFSUtil(adjList, startVertex, visited);
}

int main() {
    Node* adjList[MAX] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);

    DFS(adjList, 0);

    return 0;
}
