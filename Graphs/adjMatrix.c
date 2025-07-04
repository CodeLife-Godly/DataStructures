#include <stdio.h>
#include <stdlib.h>

//stack
typedef struct Stack{
    int top,capacity;
    int *arr;
}Stack;

Stack *stack(int size){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = size;
    stack->top = -1;
    stack->arr = (int*)calloc(size,sizeof(int));

    return stack;
}

void push(Stack *stack,int data){
    if(stack->top == stack->capacity-1){
        printf("Overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = data;
}

int pop(Stack *stack){
    if(stack->top == -1){
        printf("Underflow\n");
        return -999;
    }
    return stack->arr[(stack->top)--];
}

int stackEmpty(Stack *stack){
    if(stack->top == -1) return 1;
    return 0;
}

//queue
typedef struct Queue{
    int front,rear,capacity;
    int *arr;
}Queue;

Queue *queue(int size){
    Queue *queue = (Queue*)malloc(sizeof(queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = size;

    queue->arr = (int*)calloc(size,sizeof(int));

    return queue;
}

int queueEmpty(Queue *queue){
    if(queue->front > queue->rear) return 1;
    return 0;
}

void enqueue(Queue *queue,int data){
    if(queue->rear == queue->capacity - 1){
        printf("Overflow\n");
        return;
    }
    queue->arr[++(queue->rear)] = data;
}

int dequeue(Queue *queue){
    if(queueEmpty(queue)){
        printf("Underflow\n");
        return -999;
    }
    int temp = queue->arr[queue->front];

    if(queue->rear == queue->front){
        queue->front = queue->rear = -1;
    }
    ++queue->front;
    return temp;
}

typedef struct graph{
    int vertices;
    int **adj;
}graph;

graph *Graph(int vertices){
    graph *g = (graph*)malloc(sizeof(graph));
    g->vertices = vertices;

    g->adj = (int**)calloc(vertices,sizeof(int*));
    for(int i=0;i<vertices;++i){
        g->adj[i] = (int*)calloc(vertices,sizeof(int));
    }
    return g;
}

void DFSUtil(graph *Graph,Stack *stack,int vertex,int *visited){
    push(stack,vertex);

    while(!stackEmpty(stack)){
        int vertice = pop(stack);
        visited[vertice] = 1;
        printf("%c ",vertice+'a');

        for(int i=0;i<Graph->vertices;++i){
            if(Graph->adj[vertice][i] == 1 && visited[i] == 0){
                push(stack,i);
            }
        }
    }
    printf("\n");
}

void DFS(graph *Graph,int vertex){
    Stack *st = stack(Graph->vertices);
    int *visited = (int*)calloc(Graph->vertices,sizeof(int));

    printf("DFS: ");
    DFSUtil(Graph,st,vertex,visited);
}

void BFSUtil(graph *Graph,Queue *queue,int *visited,int vertex){
    enqueue(queue,vertex);

    while(!queueEmpty(queue)){
        int vertice = dequeue(queue);
        //marked as visited
        visited[vertice] = 1;
        printf("%c ",vertice+'a');

        for(int i=0;i<Graph->vertices;++i){
            if(Graph->adj[vertice][i] == 1 && visited[i] == 0){
                //eligible neighbor found
                enqueue(queue,i);
            }
        }
    }
    printf("\n");
}

void BFS(graph *Graph,int vertex){
    int *visited = (int*)calloc(Graph->vertices,sizeof(int));
    Queue *q = queue(Graph->vertices);

    printf("BFS: ");
    BFSUtil(Graph,q,visited,vertex);
}

void addEdge(graph *Graph,int src,int des){
    Graph->adj[src][des] = 1;
    Graph->adj[des][src] = 1;
}

void printGraph(graph *Graph){
    for(int i=0;i<Graph->vertices;++i){
        printf("%c:",i+'a');
        for(int j=0;j<Graph->vertices;++j){
            if(Graph->adj[i][j] == 1){
                printf("%c ",j+'a');
            }
        }
        printf("\n");
    }    
}

int main(){
    int vertices = 6;
    graph *G = Graph(vertices); 

    addEdge(G,0,1);
    addEdge(G,0,2);
    addEdge(G,1,3);
    addEdge(G,3,5);
    addEdge(G,1,4);

    printf("The graph is:\n");
    printGraph(G);
    DFS(G,0);
    BFS(G,0);
    return 0;
}
