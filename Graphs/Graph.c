#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Adjacency list
struct AdjList {
    struct Node* head;
};

// Graph structure
struct Graph {
    int V;
    struct AdjList* array;
};

// Queue structure for BFS
struct Queue {
    int* items;
    int front, rear, size, capacity;
};

// Stack structure for DFS
struct Stack {
    int* items;
    int top;
    int capacity;
};

// Create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* pCrawl = graph->array[v].head;
        printf("Adjacency list of vertex %d\n head", v);
        while (pCrawl) {
            printf(" -> %d", pCrawl->vertex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// --- BFS Implementation ---

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items = (int*)malloc(capacity * sizeof(int));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool isQueueEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int value) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = value;
    q->size++;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void BFS(struct Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    struct Queue* q = createQueue(graph->V);

    visited[start] = true;
    enqueue(q, start);

    printf("BFS traversal starting from %d: ", start);
    while (!isQueueEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        struct Node* temp = graph->array[current].head;
        while (temp) {
            int adj = temp->vertex;
            if (!visited[adj]) {
                visited[adj] = true;
                enqueue(q, adj);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(q->items);
    free(q);
}

// --- DFS Implementation ---

void DFSUtil(struct Graph* graph, int v, bool* visited) {
    visited[v] = true;
    printf("%d ", v);

    struct Node* temp = graph->array[v].head;
    while (temp) {
        int adj = temp->vertex;
        if (!visited[adj])
            DFSUtil(graph, adj, visited);   //recursion (stack)
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    printf("DFS traversal starting from %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

// Free memory
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->array[i].head;
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->array);
    free(graph);
}

// --- Main function ---
int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printGraph(graph);

    BFS(graph, 0);
    DFS(graph, 0);

    freeGraph(graph);
    return 0;
}
