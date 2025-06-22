#include <stdio.h>
#include <stdlib.h>

int missing(int* arr,int size){
    int temp = 1;
    for(int i=0;i<size;++i){
        if(temp==arr[i]){
            temp+=1;
        }
    }
    return temp;
}
int main(){
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* arr = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",&arr[i]);
    }

    int num = missing(arr,size);
    printf("Smallest missing number is:%d",num);
    free(arr);
    
    return 0;
}