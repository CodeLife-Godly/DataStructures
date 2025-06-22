#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *lchild,*rchild;
}Node;

Node* createnode(int info){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->info = info;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

int search(int* inorder,int start,int end,int val){
    for(int i = start;i<=end;++i){
        if(val == inorder[i]){
            return i;
        }
    }
    return -1;
}

Node *buildTree(int* postorder,int* inorder,int start,int end,int* postIndex){
    if(start>end) return NULL;

    int val = postorder[*postIndex];
    Node* root = createnode(val);
    (*postIndex)--;

    if(start == end) return root;

    int mid = search(inorder,start,end,val);

    root->rchild = buildTree(postorder,inorder,mid+1,end,postIndex);
    root->lchild = buildTree(postorder,inorder,start,mid-1,postIndex);

    return root;
}

void preOrder(Node* root){
    if(root){
        //root left right
        printf("%d ",root->info);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main(){
    int inorder[]= {1,2,3,4,5,6,7};
    int postorder[] = {1,3,2,5,7,6,4};
    int size = sizeof(inorder)/sizeof(inorder[0]);
    int postIndex = size-1;

    Node* root = buildTree(postorder,inorder,0,size-1,&postIndex);
    printf("Pre order traversal:");
    preOrder(root);

    return 0;
}