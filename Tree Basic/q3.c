#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *createnode(int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}
 
struct Node *Insert(struct Node *root,int value){
    if(root == NULL) return createnode(value);
    else if(value < root->info){
        root->lchild = Insert(root->lchild,value);
    }
    else{
        root->rchild = Insert(root->rchild,value);
    }
}

void InOrder(struct Node *root){
    if(root){
        InOrder(root->lchild);
        printf("%d ",root->info);
        InOrder(root->rchild);
    }
}

void PreOrder(struct Node *root){
    if(root){
        printf("%d ",root->info);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void PostOrder(struct Node *root){
    if(root){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d ",root->info);
    }
}

int main(){
    struct Node *root = NULL;
    int arr[] = {23,12,10,5,34,39,32};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;++i){
        root = Insert(root,arr[i]);
    }
    printf("In Order traversal:");
    InOrder(root);
    printf("\nPreOrder traversal:");
    PreOrder(root);
    printf("\nPostOrder traversal:");
    PostOrder(root);
    return 0;
}