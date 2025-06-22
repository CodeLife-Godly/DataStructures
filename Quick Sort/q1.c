#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparison = 0;


int pivot_Index(int *arr,int low,int high){
    int random_index = low + rand()%(high-low+1);
    int temp = arr[random_index];
    arr[random_index] = arr[high];
    arr[high] = temp;
    int pivot = arr[high];
    int index = low;

    for(int i=low;i<high;++i){
        ++comparison;
        if(arr[i]<pivot){
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            ++index;
        }
    }
    int value = arr[index];
    arr[index] = arr[high];
    arr[high] = value;

    return index;
}

void quick_sort(int *arr,int low,int high){
    if(low < high){
        int index = pivot_Index(arr,low,high);
        quick_sort(arr,low,index-1);
        quick_sort(arr,index+1,high);
    }
}

int main(){
    printf("Enter size of array:");
    int size;
    scanf("%d",&size);
    int *arr = (int*)malloc(size*sizeof(int));

    for(int i = 0;i<size;++i){
        printf("Enter :");
        scanf("%d",&arr[i]);
    }
    srand(time(NULL));
    clock_t start = clock();
    printf("Sorted after quick_sort:");
    quick_sort(arr,0,size-1);
    clock_t end = clock();

    double time_taken = (double)(start-end)/CLOCKS_PER_SEC;

    for(int i = 0;i<size;++i){
        printf("%d ",arr[i]);
    }

    printf("Number of comparisons:%ld\n",comparison);
    printf("Time taken:%.4f\n",time_taken);
    free(arr);
    return 0;
}
