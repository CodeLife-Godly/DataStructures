#include <stdio.h>
#include <stdlib.h>

void segregate(int* arr,int size){
    int low = 0,super = size-1; int high = super;
    while(low<high){
        if(arr[low]==1 && arr[high]==0){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            ++low;
            --high;
        }
        if(arr[low]==0){
            ++low;
        }
        if(arr[high]==1){
            --high;
        }
    }
}
int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* array = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",&array[i]);
    }
    segregate(array,size);

    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    free(array);
    return 0;
}