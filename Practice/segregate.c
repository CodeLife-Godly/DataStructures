#include <stdio.h>
#include <stdlib.h>

void segregate(int* arr,int size){
    int low = 0,high = size-1;
    while(low<high){   
        if(arr[low] == 1 && arr[high] == 0){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
        if(arr[low] == 0){
            low+=1;
        }
        if(arr[high] == 1){
            high -= 1;
        }
    }
}
int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* arr = (int*)malloc(sizeof(int)*size);
    printf("Enter the elements of array:\n");
    for(int i=0;i<size;i++){
        printf("Enter:");
        scanf("%d",&arr[i]);
    }
    segregate(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
