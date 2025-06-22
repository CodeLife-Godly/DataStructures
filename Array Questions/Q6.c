#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* array = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",array+i);
    }
    //bubble sort
    for(int i=0;i<size-1;++i){ 
        int swapped = 0;
        for(int j=0;j<size-1-i;++j){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    printf("After sorting array is:");
    for(int i=0;i<size;++i){
        printf("%d ",*(array+i));
    }
    free(array);
}