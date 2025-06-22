#include <stdio.h>
#include <stdlib.h>

int** allocate_memory(int rows,int columns){
    int** matrix = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        matrix[i] = (int*)malloc(sizeof(int)*columns);
    }
    return matrix;
}
void free_matrix(int** matrix,int rows){ 
    for(int i=0;i<rows;i++){
        free(matrix[i]);
    }
    free(matrix);
}
void printmatrix(int rows,int columns,int** matrix){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows,columns;
    printf("Enter the number of rows:");
    scanf("%d",&rows);
    printf("Enter the number of columns:");
    scanf("%d",&columns);

    int** matrix = allocate_memory(rows,columns);

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter element [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    
    printf("Matrix is:\n");
    printmatrix(rows,columns,matrix);
    printf("Transpose of matrix is:\n");
    for(int i=0;i<rows;i++){
        for(int j=rows-1;j>=i;j--){         //traversing only upper half
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printmatrix(rows,columns,matrix);

    free_matrix(matrix,rows);
    return 0;
}