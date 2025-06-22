#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
   struct Node *lchild,*rchild;
}Node;

Node* createnode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

//preorder extraction
void extract(Node *root,int *arr,int *index){
    if(root){
        arr[(*index)++] = root->info;
        extract(root->lchild,arr,index);
        extract(root->rchild,arr,index);
    }
}

void heapify(int* arr,int size,int index){
    int largest = index; //assume largest one's (index)
    int left = 2*index + 1; //left child
    int right = 2*index + 2; //right child

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    //if we changed the largest
    if(largest != index){
        //then swap 
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        heapify(arr,size,largest);
    }
}

void heapsort(int* arr,int size){
    for(int i = size/2-1;i>=0;--i){
        heapify(arr,size,i);
    }

    for(int i=size-1;i>0;--i){
        //largest is at first position
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr,i,0);  //size = i and largest is first 
    }
}

int main(){
    Node *root = createnode(6);
    root->lchild = createnode(2);
    root->rchild = createnode(7);
    root->lchild->lchild = createnode(1);
    root->lchild->rchild = createnode(3);
    root->rchild->lchild = createnode(5);
    root->rchild->rchild = createnode(4);

    int arr[100],index = 0;
    extract(root,arr,&index);

    heapsort(arr,index);
    for(int i=0;i<index;++i){
        printf("%d ",arr[i]);
    }
    return 0;
}