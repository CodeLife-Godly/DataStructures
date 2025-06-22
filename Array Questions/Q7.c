#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    printf("Enter details of array:\n");
    int* array = (int*)malloc(size*sizeof(int));
    int* copied = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",array+i);
    }

    for(int i=0;i<size;++i){
        *(copied+i) = *(array+i);
    }
    printf("Data copied successfully\n");
    free(array);
    free(copied);
    return 0;   
}