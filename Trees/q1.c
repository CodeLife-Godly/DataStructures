#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *lchild,*rchild;
}Node;

Node* createnode(int val){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->info = val;
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

Node* BuildTree(int* inorder,int* preorder,int start,int end,int* preindex){
    if(start>end) return NULL;

    int root_value = preorder[*preindex];
    Node* root = createnode(root_value);
    (*preindex)++;

    if(start == end) return root;

    int mid = search(inorder,start,end,root_value);
 
    //left of mid in inorder will make left child
    //right of mid in inorder will make right child

    root->lchild = BuildTree(inorder,preorder,start,mid-1,preindex);
    root->rchild = BuildTree(inorder,preorder,mid+1,end,preindex);

    return root;
}

void postorder(Node *root){
    // left right root
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->info);
    }
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7};
    int preorder[] = {4,2,1,3,6,5,7};
    int inorder_size = sizeof(inorder)/sizeof(inorder[0]);
    int preindex = 0;

    Node* tree = BuildTree(inorder,preorder,0,inorder_size-1,&preindex);
    printf("Postorder traversal:");
    postorder(tree);

    return 0;
}