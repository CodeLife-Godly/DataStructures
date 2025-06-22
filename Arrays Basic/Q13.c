#include <stdio.h>
#include <stdlib.h>


int main(){
    int size;
    printf("Enter the size of your array:");
    scanf("%d",&size);
    int* arr = (int*)malloc(sizeof(int)*size);

    printf("Enter the elements of array:\n");
    for(int i=0;i<size;i++){
        printf("Enter:");
        scanf("%d",arr+i);
    }
    int swapped = 0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    printf("Max of array is:%d\n",arr[size-1]);
    printf("Min of array is:%d\n",arr[0]);

    free(arr);
    return 0;
}