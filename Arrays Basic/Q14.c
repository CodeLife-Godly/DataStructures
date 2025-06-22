#include <stdio.h>
#include <stdlib.h>

void print_array(int* array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return;
}
int main(){
    int size,count = 0;
    printf("Enter the size of your array:");
    scanf("%d",&size);
    int* array = (int*)malloc(sizeof(int)*size);

    printf("Enter the elements of array:\n");
    for(int i=0;i<size;i++){
        printf("Enter:");
        scanf("%d",array+i);
    }
    printf("The original array is:\n");

    print_array(array,size);

    printf("The array after moving zeroes to end:\n");

    for(int i=0;i<size;i++){
        if(array[i] != 0){
            array[count] = array[i];
            count += 1;
        }
    }
    for(int i=count;i<size;i++){
        array[i] = 0;
    }
    print_array(array,size);

    free(array);
    return 0;
}