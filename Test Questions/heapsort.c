// Online C compiler to run C program online
#include <stdio.h>

void heapify(int *arr,int i,int size){
    int largest = i;
    int lchild = 2*i+1;
    int rchild = 2*i + 2;
    
    if(lchild < size && arr[largest] < arr[lchild]){
        largest = lchild;
    }
    if(rchild < size && arr[largest] < arr[rchild]){
        largest = rchild;
    }
    
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        //change the affected one 
        heapify(arr,largest,size);
    }
}

void heapsort(int *arr,int size){
    int non_leaf = size/2;
    
    for(int i=non_leaf;i>=0;--i){
        heapify(arr,i,size);
    }
    //converted to max heap
    for(int i=size-1;i>0;i--){
        int temp = arr[0];  //largest element
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr,0,i);   //heapfiy 1st element 
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    printf("Sorted array is \n");
    printArray(arr,n);
    return 0;
}