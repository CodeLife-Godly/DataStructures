#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int* array,int size,int* comparisons){
    for(int i=0;i<size-1;++i){
        int swapped = 0;
        for(int j=0;j<size-1-i;++j){
            (*comparisons)++;
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}
int main(){
    int size,comparisons=0;

    printf("Enter the size of array:");
    scanf("%d",&size);
    int* array = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",array+i);
    }
    clock_t start_time = clock();
    bubble_sort(array,size,&comparisons);
    clock_t end_time = clock();

    double time_taken = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Array is sorted now\n");
    printf("Comparisons made are:%d\n",comparisons);
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
    }
    printf("\nTime taken:%lf\n",time_taken);
    free(array);
    return 0;
}