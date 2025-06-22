#include <stdio.h>
#include <stdlib.h>


struct Node{
    int info;
    struct Node *rchild;
    struct Node *lchild;
};

struct Node *createnode(int info){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->info = info;
    newnode->rchild = newnode->lchild = NULL;
    return newnode;
}

void insert(struct Node **root,int data){
    struct Node *temp = createnode(data),*ptr = *root;
    if(*root == NULL){
        *root = temp;
        return;
    }

    while(1){
        if(data == ptr->info) return;
        else if(data < ptr->info){
            //go to left
            if(ptr->lchild){
                ptr = ptr->lchild;
            }
            else{
                ptr->lchild = temp;
                break;
            }   
        }
        else{
            //go to right
            if(ptr->rchild){
                ptr = ptr->rchild;
            }
            else{
                ptr->rchild = temp;
                break;
            }
        }
    }
}

void Display(struct Node *root){
    if(root){
        Display(root->lchild);
        printf("%d ",root->info);
        Display(root->rchild);
    }
}

int main(){
    struct Node *root = NULL;
    int arr[] = {23,12,10,5,34,39,14};
    for(int i=0;i<7;++i){
        insert(&root,arr[i]);
    }
    Display(root);

    return 0;
}