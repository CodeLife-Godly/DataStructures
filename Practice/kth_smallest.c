#include <stdio.h>
#include <limits.h>

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int* arr,int low,int pivot,int high){
    int count = 0;
    int key = arr[pivot];
    swap(&arr[pivot],&arr[high]);

    for(int i=low;i<high;++i){
        if(arr[i]<key){
            swap(&arr[count],&arr[i]);
            ++count;
        }   
    }
    swap(&arr[count],&arr[high]);

    return count;
}
int insertion(int* arr,int size){
    for(int i=1;i<size;++i){
        int position = i;
        while(arr[position-1]>arr[i] && position > 0){
            arr[position] = arr[position-1];
            --position;
        }
        arr[position] = arr[i];
    }
}
int find_median(int* arr,int low,int high){
    int size = high-low+1;
    insertion(arr,size);

    return arr[low + (high-low)/2];
}
int MedianOfMedians(int* arr,int low,int high){
    iF(high-low < 5){
        return find_median(arr,low,high)
    }

    int numMedians = (high-low+5)/5;
    int medians[numMedians];

    for(int i=0;i<numMedians;++i){
        int subLow = low + i*5;
        
    }
}
int main(){

}