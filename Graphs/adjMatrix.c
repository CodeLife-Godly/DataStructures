// Online C compiler to run C program online
#include <stdio.h>
#define VERTICES 10

int adjMatrix[VERTICES][VERTICES];
int numVertices;

void Graph(int vertices){
    numVertices = vertices;
    for(int i=0;i<numVertices;++i){
        for(int j=0;j<numVertices;++j){
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src,int des){
    adjMatrix[src][des] = 1;
    adjMatrix[des][src] = 1;
}

void printGraph(){
    for(int i=0;i<numVertices;++i){
        for(int j=0;j<numVertices;++j){
            if(adjMatrix[i][j] == 1){
                printf("%d--%d\n",i,j);
            }
        }
    }    
}

int main(){
    int vertices = 5;
    Graph(vertices);

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printGraph();

    return 0;
}