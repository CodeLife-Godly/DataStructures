#include <stdio.h>
#include <stdlib.h>

void linear_search(int* array,int size,int target){
    
}
int main(){
    int target,size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* array = (int*)malloc(sizeof(int)*size);
    printf("Enter elements of array:\n");
    for(int i=0;i<size;i++){
        printf("Enter:");
        scanf("%d",array+i);
    }
    printf("Enter the target in array:");
    scanf("%d",&target);

    for(int i=0;i<size;i++){
        if(array[i]==target){
            printf("Target found at index %d\n",i);
            free(array);
            return 0;
        }
    }
    printf("Target not found\n");
    free(array);
    return 0;
}