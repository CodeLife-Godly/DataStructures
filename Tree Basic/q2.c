#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *lchild,*rchild;
};

struct Node *createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

struct Node* Insert(struct Node *root,int data){
    if(root == NULL) return createnode(data);
    else if(root->info > data){
        root->lchild = Insert(root->lchild,data);
    }
    else{
        root->rchild = Insert(root->rchild,data);
    }
    return root;
}

int Search(struct Node *root, int value){
    struct Node *ptr = root;
    while(ptr){
        if(value == ptr->info) return 1;
        else if(value < ptr->info) ptr = ptr->lchild;
        else ptr = ptr->rchild;
    }
    return 0;
}

struct Node *findMin(struct Node *root){
    while(root->lchild){
        root = root->lchild;
    }
    return root;
}

struct Node *Delete(struct Node *root,int key){
    //no child
    if(root == NULL) return NULL;

    if(key < root->info){
        root->lchild = Delete(root->lchild,key); 
    }
    else if(key > root->info){
        root->rchild = Delete(root->rchild,key);
    }
    else{
        //node found
        //one child
        if(root->rchild == NULL){
            //left child exists, so delete it
            struct Node *temp = root->lchild;
            free(root);
            return temp;
        }
        else if(root->lchild == NULL){
            //delete the right child
            struct Node *temp = root->rchild;
            free(root);
            return temp;
        }
        else{
            //both child exist
            //replace node with inorder successor
            //which is the smallest node in right subtree MIN(root->rchild)
            //or the left extreme of right child
            struct Node *temp = findMin(root->rchild); //get the inorder successor
            root->info = temp->info;
            //now delete the inorder successor
            root->rchild = Delete(root->rchild,temp->info);
        }
    }
}

void Display(struct Node *root){
    if(root){
        //go to left subtree
        Display(root->lchild);
        //print the node
        printf("%d ",root->info);
        //go to right subtree
        Display(root->rchild);
    }
}

int main(){
    struct Node *root = NULL;
    int arr[] = {10,12,1,5,6,20,30,2,3};
    
    for(int i = 0;i<9;++i){
        root = Insert(root,arr[i]);
    }
    Display(root);
    root = Delete(root,20);
    printf("\n");
    Display(root);
    return 0;
}