#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *lchild,*rchild;
}Node;

Node *createnode(int info){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->info = info;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

Node* Insert(Node *root,int value){
    if(root == NULL) return createnode(value);

    if(value > root->info){
        root->rchild = Insert(root->rchild,value);
    }
    else{
        printf("Invalid\n");
    }
    return root;
}

void inorder(Node *root){
    if(root){
        inorder(root->lchild);
        printf("%d ",root->info);
        inorder(root->rchild);
    }
}

int main(){
    Node *root = NULL;
    int arr[] = {10,20,40,50,90,100};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;++i){
        root = Insert(root,arr[i]);
    }
    printf("Inorder:");
    inorder(root);
    return 0;
}
