#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    if(size<=0){
        printf("Can't copy data,enter valid size\n");
        return 0;
    }
    printf("Enter details of array:\n");

    int* array = (int*)malloc(size*sizeof(int));
    int* copied = (int*)malloc(size*sizeof(int));
    if(array == NULL || copied == NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }
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