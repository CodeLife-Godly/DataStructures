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
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void input(int** matrix,int rows,int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter element at [%d][%d]:",i,j);
            scanf("%d",*(matrix+i)+j);   //*(matrix+i) = matrix[i] is still a pointer or reference to a memory location
        }
    }
    printf("The array you entered is:\n");
    printmatrix(matrix,rows,columns);
}
void multiply_matrices(int** matrix1,int** matrix2,int rows1,int columns1,int rows2,int columns2){
    if(columns1 != rows2){
        printf("Can't multiply these matrices!\n");
        return;
    }
    int** result = allocate_memory(rows1,columns2);

    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            int temp = 0;
            for(int k=0;k<columns1;k++){
                temp += matrix1[i][k]*matrix2[k][j];
            }
            result[i][j] = temp;
        }
    }
    printf("Result of multiplication is:\n");
    printmatrix(result,rows1,columns2);
    free_matrix(result,rows1);
}
int main(){
    int rows1,columns1,rows2,columns2;

    printf("Input data for 1st matrix:\n");
    printf("Enter the number of rows:");
    scanf("%d",&rows1);
    printf("Enter the number of columns:");
    scanf("%d",&columns1);

    int** matrix1 = allocate_memory(rows1,columns1);
    input(matrix1,rows1,columns1);

    printf("Input data for 2nd matrix:\n");
    
    printf("Enter the number of rows for 2nd matrix:");
    scanf("%d",&rows2);
    printf("Enter the number of columns for 2nd matrix:");
    scanf("%d",&columns2);
    
    int** matrix2 = allocate_memory(rows2,columns2);
    input(matrix2,rows2,columns2);
    
    multiply_matrices(matrix1,matrix2,rows1,columns1,rows2,columns2);
    free_matrix(matrix1,rows1);
    free_matrix(matrix2,rows2);
    
    return 0;
}