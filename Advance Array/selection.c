#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* array,int size){
    for(int i=0;i<size;++i){
       int position = i;
       for(int j=i;j<size;++j){
            if(array[j] < array[position]){
                position = j;
            }
        }
        int temp = array[position];
        array[position] = array[i];
        array[i] = temp;
    }
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
    selection_sort(array,size);
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
    }  
    free(array);
    return 0;
}