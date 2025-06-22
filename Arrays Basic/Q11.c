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
void input(int** matrix,int rows,int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter element at [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

int main(){
    int rows,columns;
    printf("Enter the number of rows:");
    scanf("%d",&rows);
    printf("Enter the number of columns:");
    scanf("%d",&columns);

    printf("Enter the details for 1st matrix:\n");
    int** matrix1 = allocate_memory(rows,columns);
    input(matrix1,rows,columns);

    printf("Enter the details for 2nd matrix:\n");
    int** matrix2 = allocate_memory(rows,columns);
    input(matrix2,rows,columns);

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matrix1[i][j] != matrix2[i][j]){
                printf("Matrices are not identical!\n");
                free_matrix(matrix1,rows);
                free_matrix(matrix2,rows);
                return 0;
            }
        }
    }
    printf("They are identical!\n");

    free_matrix(matrix1,rows);
    free_matrix(matrix2,rows);
    
    return 0;
}