#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparison = 0;

void merge(int *arr,int low,int middle,int high){
    int size_left = middle-low+1;
    int size_right = high-middle;

    int *left = (int*)malloc(size_left*sizeof(int));
    int *right = (int*)malloc(size_right*sizeof(int));

    for(int i=0;i<size_left;++i){
        left[i] = arr[i+low];
    }
    for(int i=0;i<size_right;++i){
        right[i] = arr[i+middle+1];
    }
    //arrays are copied
    int j=0,k=0,i=low;
    while(j < size_left && k < size_right){
        ++comparison;
        if(left[j]<=right[k]){
            arr[i] = left[j];
            ++j;
        }
        else{
            arr[i] = right[k];
            ++k;
        }
        ++i;
    }
    while(j < size_left){
        arr[i] = left[j];
        ++j;
        ++i; 
    }
    while(k < size_right){
        arr[i] = right[k];
        ++k;
        ++i;
    }
    free(left);
    free(right);
}

void merge_sort(int *array,int low,int high){
    if(low<high){
        int middle = low + (high-low)/2;
        merge_sort(array,low,middle);
        merge_sort(array,middle+1,high);

        merge(array,low,middle,high);
    }
}

int main(){
    printf("Enter size of array:");
    int size;
    scanf("%d",&size);
    int *arr = (int*)malloc(size*sizeof(int));

    for(int i = 0;i<size;++i){
        printf("Enter:");
        scanf("%d",&arr[i]);
    }
    srand(time(NULL));
    clock_t start = clock();
    merge_sort(arr,0,size-1);
    clock_t end = clock();

    double time_taken = (double)(start-end)/CLOCKS_PER_SEC;

    for(int i = 0;i<size;++i){
        printf("%d ",arr[i]);
    }

    printf("Number of comparisons:%ld\n",comparison);
    printf("Time taken:%.4f\n",time_taken);
    printf("Estimated space:%ld bytes\n",2*sizeof(int)*size);

    free(arr);
    return 0;
}
