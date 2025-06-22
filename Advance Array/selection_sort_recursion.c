#include <stdio.h>
#include <stdlib.h>

void selection_recursion(int* array,int sorted,int size){
    if(sorted>=size-1){
        return;
    }
    int position = sorted;
    for(int j=sorted+1;j<size;++j){
        if(array[j]<array[position]){
            position = j;
        }
    }
    int temp = array[position];
    array[position] = array[sorted];
    array[sorted] = temp;
    selection_recursion(array,sorted+1,size);
}
void selection_sort_start(int* array,int size){
    selection_recursion(array,0,size);
}
int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* array = (int*)malloc(size*sizeof(int));
    printf("Enter the details of array:\n");

    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",array+i);
    } 
    selection_sort_start(array,size);
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
    }  
    free(array);
    return 0;
}