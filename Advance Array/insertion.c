#include <stdio.h>
#include <stdlib.h>

void insertion(int* array,int size){
    for(int i=1;i<size;++i){
        int key = array[i];
        int position = i;
        //assume left part to be sorted so only need to check
        //array[position]>key
        while(position>0 && array[position-1]>key){
            array[position] = array[position-1];
            --position;
        }
        array[position] = key;
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
    insertion(array,size);
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
    }  
    free(array);
    return 0;
}