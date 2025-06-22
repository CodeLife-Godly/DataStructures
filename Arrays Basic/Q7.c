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
void printmatrix(int** matrix,int rows,int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void op_matrices(int** matrix1,int** matrix2,int rows,int columns,char operation){
    int** result = allocate_memory(rows,columns);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(operation == '+'){
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
            else{
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }
    printf("Result of operation is:\n");
    printmatrix(result,rows,columns);
    free_matrix(result,rows);
}
void input(int rows,int columns,int** matrix){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter element at [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

int main(){
    int rows,columns;
    printf("Enter the number of rows of matrix:");
    scanf("%d",&rows);
    printf("Enter the number of columns of matrix:");
    scanf("%d",&columns);

    int** matrix1 = allocate_memory(rows,columns);
    int** matrix2 = allocate_memory(rows,columns);

    printf("Enter the elements of first matrix now:\n");
    input(rows,columns,matrix1);

    printf("Enter the elements of second matrix now:\n");
    input(rows,columns,matrix2);

    printf("Enter + if you want to add and - if you want to subtract:");
    char operation;
    scanf(" %c",&operation);
    
    op_matrices(matrix1,matrix2,rows,columns,operation);
    free_matrix(matrix1,rows);
    free_matrix(matrix2,rows);
    return 0;
}
