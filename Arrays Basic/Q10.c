#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows,columns;
    printf("Enter the number of rows:");
    scanf("%d",&rows);
    printf("Enter the number of columns:");
    scanf("%d",&columns);

    if(rows!=columns){
        printf("Diagonal elements of matrix is only defined when matrix is a square!\n");
        return -1;
    }

    int** matrix = (int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        matrix[i] = (int*)malloc(sizeof(int)*columns);
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter the elements at [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("The diagonal entries of matrix is:\n");
    for(int i=0;i<rows;i++){
        printf("%d\n",matrix[i][i]);    
    }
    for(int i=0;i<rows;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;

}