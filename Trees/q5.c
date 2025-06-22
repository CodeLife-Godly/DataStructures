#include <stdio.h>
#include <stdlib.h>

//implement a binary tree
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

Node *Insert(Node *root,int value){
    if(root == NULL) return createnode(value);

    if(value > root->info){
        //go right
        root->rchild = Insert(root->rchild,value);
    }
    else{
        root->lchild = Insert(root->lchild,value);
    }
    return root;
}

//finding inorder successor
Node *FindMin(Node *root){
    while(root->lchild != NULL){
        root = root->lchild;
    }
    return root;
}

Node *delete(Node *root,int value){
    if(root == NULL) return root;

    if(value < root->info){
        //go left
        root->lchild = delete(root->lchild,value);
    }
    else if(value > root->info){
        //go right 
        root->rchild = delete(root->rchild,value);
    }
    else{
        //node found
        //one child
        if(root->lchild == NULL){
            Node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild == NULL){
            Node *temp = root->lchild;
            free(root);
            return temp;
        }
        else{
            //two children
            //inorder successor is the least node in the right subtree
            Node *temp = FindMin(root->rchild);
            root->info = temp->info;
            //delete that inorder successor, can't just free it as it may have children
            root->rchild = delete(root->rchild,temp->info);
        }
    }
    //after everything, now return root
    return root;
}

int Cardinality(Node *root){
    if(root == NULL) return 0;

    return 1 + Cardinality(root->lchild) + Cardinality(root->rchild);
}

int LeafCardinality(Node *root){
    if(root == NULL) return 0;

    if(root->lchild == NULL && root->rchild == NULL) return 1;
    else{
        return LeafCardinality(root->lchild) + LeafCardinality(root->rchild);
    }
}

int NonLeafCardinality(Node *root){
    if(root == NULL) return 0;

    if(root->lchild || root->rchild){
        return 1 + NonLeafCardinality(root->lchild) + NonLeafCardinality(root->rchild);
    }
    return 0;
}

int equal(Node *root1,Node *root2){
    //both of them empty
    if(root1 == NULL && root2 == NULL) return 1;
    //one of them empty
    if(root1 == NULL || root2 == NULL) return 0;

    if(root1->info != root2->info) return 0;

    return equal(root1->lchild,root2->lchild) && equal(root1->rchild,root2->rchild);
}   

int height(Node *root){
    if(root == NULL) return 0;

    int left_height = height(root->lchild);
    int right_height = height(root->rchild);

    int max = (left_height > right_height) ? left_height:right_height;
    //final height = 1 (of node) + max(leftsubtree,right subtree)
    return 1+max;
}

int strict(Node *root){
    if(root == NULL) return 1;

    if((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL)){
        return 0;   //zero if one child
    }
    return strict(root->lchild) && strict(root->rchild);
}

void inorder(Node *root){
    if(root){
        inorder(root->lchild);
        printf("%d ",root->info);
        inorder(root->rchild);
    }
}

void preorder(Node *root){
    if(root){
        printf("%d ",root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(Node *root){
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->info);
    }
}

int main(){
    Node *root = NULL;
    int arr[] = {10,20,30,12,4,5,7,8,25,11,100};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;++i){
        root = Insert(root,arr[i]);
    }
    printf("Number of nodes in BST:%d\n",Cardinality(root));
    printf("Inorder:");
    inorder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);

    printf("\nEnter node to delete:");
    int val;
    scanf("%d",&val);
    root = delete(root,val);
    printf("Inorder:");
    inorder(root);
    printf("\nNumber of nodes in BST:%d\n",Cardinality(root));
    printf("VALUE OF ROOT NODE:%d\n",root->info);
    printf("Leaf Cardinality:%d\n",LeafCardinality(root));
    printf("Non Leaf Cardinality:%d\n",NonLeafCardinality(root));
    printf("Height:%d\n",height(root));
    if(strict(root)){
        printf("Strict\n");
    }
    else{
        printf("Not strict\n");
    }
    return 0;
}


