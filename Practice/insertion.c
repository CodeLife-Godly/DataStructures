#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int *arr,int size){
    for(int i=1;i<size;++i){
        int key = arr[i];  
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int *arr,int size){
    int swapped;
    for(int i=0;i<size-1;++i){
        for(int j=0;j<size-1-i;++i){
            swapped = 0;
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

void selection_sort(int *arr,int size){
    for(int i=0;i<size-1;++i){
        int min_index = i;
        for(int j=i+1;j<size-1;++j){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void merge(int *arr,int low,int mid,int high){
    int size1 = (mid-low+1);
    int size2 = (high-mid);

    int arr1[size1],arr2[size2];

    for(int i=0;i<size1;++i){
        arr1[i] = arr[low+i];
    }
    for(int i=0;i<size2;++i){
        arr2[i] = arr[mid+1+i];
    }
    int i = 0,j = 0,k = low;

    while(i<size1 && j<size2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            ++i;
        }
        else{
            arr[k] = arr2[j];
            ++j;
        }
        ++k;
    }
    while(i<size1){
        arr[k] = arr1[i];
        ++i;
        ++k;
    }
    while(j<size2){
        arr[k] = arr2[j];
        ++j;
        ++k;
    }
}

void mergeSort(int* arr,int low,int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int pivotIndex(int *arr,int low,int high){
    int pivotIndex = low + rand() % (high-low+1);
    int pivot = arr[pivotIndex];

    arr[pivotIndex] = arr[high];
    arr[high] = pivot;

    int position = low;
    for(int i=low;i<high;++i){
        if(arr[i]<pivot){
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
            ++position;
        }
    }
    int var = arr[position];
    arr[position] = arr[high];
    arr[high] = var;

    return position;
}

void quicksort(int *arr,int low,int high){
    if(low<high){
        int pIndex = pivotIndex(arr,low,high);
        quicksort(arr,low,pIndex-1);
        quicksort(arr,pIndex+1,high);
    }
}

void heapify(int *arr,int root,int size){
    int lchild = 2*root + 1;
    int rchild = 2*root + 2;
    int largest = arr[root];

    if(lchild < size && arr[lchild]>arr[root]){
        largest = lchild;
    }
    if(rchild < size && arr[rchild]>arr[root]){
        largest = rchild;
    }
    if(largest != root){
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr,largest,size);
    }
}

void HeapSort(int *arr,int size){
    for(int i=0;i<= size/2 -1 ;++i){
        heapify(arr,i,size);
    }
    for(int i=size-1;i>0;--i){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr,0,size-1);
    }

}

int main(){
    int* arr = (int*)malloc(sizeof(int));
    for(int i=0;i<6;++i){
        printf("Enter:");
        scanf("%d",arr+i);
    }
    HeapSort(arr,6);
    for(int i=0;i<6;++i){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
