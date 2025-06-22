#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int coeff;
  int power;
  struct Node *next;
}Node;

Node *createnode(int coeff,int power){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->coeff = coeff;
  temp->power = power;
  
  return temp;
}

void Insert(struct Node **head,int coeff,int power){
  Node *newnode = createnode(coeff,power);
  
  if(*head == NULL){
    *head = newnode;
    return;
  }
  Node *ptr = *head;
  while(ptr->next) ptr = ptr->next;
  ptr->next = newnode;
}

Node* add(Node *p1,Node *p2){
  Node *result = NULL;
  
  while(p1 && p2){
    if(p1->power == p2->power){
      Insert(&result,p1->coeff+p2->coeff,p1->power);
      p1 = p1->next;
      p2 = p2->next;
    }
    else if(p1->power > p2->power){
      Insert(&result,p1->coeff,p1->power);
      p1 = p1->next;
    }
    else{
      Insert(&result,p2->coeff,p2->power);
      p2 = p2->next;
    }
  }
  
  while(p1){
    Insert(&result,p1->coeff,p1->power);
    p1 = p1->next;
  }
  while(p2){
    Insert(&result,p2->coeff,p2->power);
    p2 = p2->next;
  }
  
  return result;
}

void display(Node *poly){
  while(poly){
    printf("(%d , %d)->",poly->coeff,poly->power);
    poly = poly->next;
  }
  printf("NULL\n");
}

int main(){
  Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    // 4x^3 + 3x^2 + 1
    Insert(&poly1, 4, 3);
    Insert(&poly1, 3, 2);
    Insert(&poly1, 1, 0);

    // 5x^3 + 2x + 6
    Insert(&poly2, 5, 3);
    Insert(&poly2, 2, 1);
    Insert(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    sum = add(poly1, poly2);

    printf("Sum: ");
    display(sum);
    
    return 0;
  
}