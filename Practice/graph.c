#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX],front = -1,rear = -1;

typedef struct Graph{
    int V;
    int **adjMatrix;
}Graph;

void enqueue(int item){
    if(rear == MAX-1){
        printf("Wrong\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue(){
    if(front==-1 || front>rear){
        printf("Underflow\n");
        return -999;
    }
    return queue[front++];
}

Graph *createGraph(int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    
    graph->adjMatrix = (int**)calloc(V,sizeof(int*));
    for(int i=0;i<V;++i){
        graph->adjMatrix[i] = (int*)calloc(V,sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph,int src,int des){
    graph->adjMatrix[src][des] = 1;
    graph->adjMatrix[des][src] = 1;
}

void dfs_start(Graph *graph,int *visited,int vertex){
    visited[vertex] = 1;
    printf("%d ",vertex);

    for(int i=0;i<graph->V;++i){
        if(!visited[i] && graph->adjMatrix[vertex][i]){
            dfs_start(graph,visited,i);
        }
    }
}

void DFS(Graph *graph,int start){
    int *visited = (int*)calloc(graph->V,sizeof(int));
    dfs_start(graph,visited,start);
    free(visited);
}

void bfs_function(Graph *graph,int *visited,int vertex){
    enqueue(vertex);
    visited[vertex] = 1;

    while(front<=rear){
        int val = dequeue();
        printf("%d ",val);
        for(int i=0;i<graph->V;++i){
            if(!visited[i] && graph->adjMatrix[val][i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void BFS(Graph *graph,int start){
    int *visited = (int*)calloc(graph->V,sizeof(int));
    bfs_function(graph,visited,start);
}

int main(){
    Graph *graph = createGraph(5);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,4,3);
    addEdge(graph,4,2);

    DFS(graph,4);
    printf("\n");
    BFS(graph,4);
    return 0;
}