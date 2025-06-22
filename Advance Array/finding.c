#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int* arr, int low, int high,int pivotIndex) {
    int i = low, j = low;
    int pivot = arr[pivotIndex];

    while (j<high) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i],&arr[high]);
    return i;
}
int k_th(int* arr, int low, int high, int k) {
    if (k < 1 || k > high - low + 1) {
        return -1;  // Invalid k
    }
    srand(time(0));

    while (low <= high) {
        int pivotIndex = low + rand()% (high-low+1);
        int newindex = partition(arr, low, high, pivotIndex);

        if (newindex == low+k-1) {
            return arr[newindex];
        } else if (newindex < low+k-1) {
            low = newindex+1;
        } else {
            high = newindex - 1; // The pivot is the k-th element
        }
    }
    return -1;
}


int main(){
    int size,k;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int* arr = (int*)malloc(size*sizeof(int));

    for(int i=0;i<size;++i){
        printf("Enter:");
        scanf("%d",arr+i);
    }
    printf("Enter the value of k:");
    scanf("%d",&k);

    int answer = k_th(arr,0,size-1,k);
    printf("%d\n",answer);

    free(arr);
    return 0;
}


