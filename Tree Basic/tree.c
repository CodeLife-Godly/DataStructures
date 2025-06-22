#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node* lchild;
  struct Node* rchild;
};

struct Node *newnode(int data){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->info = data;
  temp->lchild = NULL;
  temp->rchild = NULL;
  
  return temp;
}

void insert(struct Node **root,int data){
  struct Node *temp = newnode(data);
  
  if(*root == NULL){
    *root = temp;
    return;
  }
  struct Node *p = *root;
  while(1){
    if(data == p->info){
      printf("Duplicate\n");
      return;
    }
    else if(data < p->info){
      //go left 
      if(p->lchild == NULL){
        p->lchild = temp;
        return;
      }
      p = p->lchild;
    }
    else{
      //go right
      if(p->rchild == NULL){
        p->rchild = temp;
        return;
      }
      p = p->rchild;
    }
  } 
}


void inorder(struct Node *root){
  if(root == NULL) return;

  inorder(root->lchild);
  printf("%d ",root->info);
  inorder(root->rchild);
}

void preorder(struct Node *root){
    if(root == NULL) return;

    printf("%d ",root->info);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(struct Node *root){
    if(root == NULL) return;

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->info);
}

int main(){
  struct Node *root = NULL;
  
  int num;
  printf("Enter the number of nodes:");
  scanf("%d",&num);
  
  for(int i = 0;i<num;++i){
    printf("Enter data:");
    int data;
    scanf("%d",&data);
    
    insert(&root,data);
  }
  printf("In order:");
  inorder(root);
  printf("\nPre-order:");
  preorder(root);
  printf("\nPost-order:");
  postorder(root);
  
  return 0;
}

  
  
  


  
  
  

