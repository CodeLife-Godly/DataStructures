#include <stdio.h>
#include <stdlib.h>

int main(){
    int length;
    printf("Enter the length of matrix:");
    scanf("%d",&length);

    printf("Enter the details for matrix:\n");
    int** matrix = (int**)malloc(sizeof(int*)*length);
    for(int i=0;i<length;i++){
        matrix[i] = (int*)malloc(sizeof(int)*length);
    }
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            printf("Enter element at [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("The lower half is:\n");
    for(int i=0;i<length;i++){
        for(int j=1;j<=i+1;j++){
            printf("%d ",matrix[i][j-1]);
        }
        printf("\n");
    }
    printf("The upper half is:\n");
    for(int i=0;i<length;i++){
        for(int j=i;j<length;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<length;i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}