#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *lchild;
    struct Node *rchild;
}Node;

Node *createnode(int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}
 
Node *Insert(Node *root,int value){
    if(root == NULL) return createnode(value);
    else if(value < root->info){
        root->lchild = Insert(root->lchild,value);
    }
    else{
        root->rchild = Insert(root->rchild,value);
    }
}

int Height(Node *root){
    if(root == NULL) return 0;
    int left_height = Height(root->lchild);
    int right_height = Height(root->rchild);

    int max = (left_height>=right_height) ? left_height:right_height;
    return 1+max;
}

int main(){
    Node *root = NULL;
    int arr[] = {10,1,13,2,14,15,4,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;++i){
        root = Insert(root,arr[i]);
    }
    printf("Height is:%d\n",Height(root));
    return 0;
}