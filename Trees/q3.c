#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *lchild,*rchild;
}Node;

Node *createnode(int info){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->info = info;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

Node *Insert(Node* root,int value){
    if(root == NULL) return createnode(value);

    if(root->info == value) return root;
    else if(value < root->info){
        //go left
        root->lchild = Insert(root->lchild,value);
    }
    else{
        //go right
        root->rchild = Insert(root->rchild,value);
    }
}

int Height(Node *root){
    if(root == NULL) return 0;

    int left_height = Height(root->lchild);
    int right_height = Height(root->rchild);
    
    int max = (left_height > right_height) ? left_height:right_height;
    return 1+max;
}

int main(){
    Node *root = NULL;
    int arr[] = {4,2,6,7,5,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;++i){
        root = Insert(root,arr[i]);
    }
    printf("The height of tree is:%d",Height(root));
    return 0;
}