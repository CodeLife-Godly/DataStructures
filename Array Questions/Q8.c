#include <stdio.h>
#include <stdlib.h>

void binary_search(int* array,int target,int low,int high){
    if(low>high){
        printf("Score not found\n");
        return;
    }
    int mid = low + (high-low)/2;
    if(array[mid]==target){
        printf("Score found at index %d\n",mid);
    }
    else if(array[mid]>target){
        //lower part
        binary_search(array,target,low,mid-1);
    }
    else{
        //upper part
        binary_search(array,target,mid+1,high);
    }
}
int main(){
    int size,target;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* array = (int*)malloc(size*sizeof(int));
    printf("Enter array in ascending order:\n");
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",array+i);
    }
    printf("Enter the score to find:");
    scanf("%d",&target);
    binary_search(array,target,0,size-1);

    free(array);
    return 0;
}