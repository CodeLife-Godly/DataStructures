//Neelansh Goyal C1 

#include <stdio.h>
#include <stdlib.h>

struct Node{
  float coeff;
  int power;
  struct Node *next;
  };

struct Node* createnode(float coeff,int power){
  struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
  
  newnode->coeff = coeff;
  newnode->power = power;
  newnode->next = NULL;
  
  return newnode;
}

void add_node(struct Node **head,float coeff,int power){
  //ignore zero terms
  if(coeff == 0) return;

  //when node is to be added to first position
  if(*head == NULL || (*head)->power < power){
    struct Node *node = createnode(coeff,power);
    node->next = *head;
    *head = node;
    return;
  }

  struct Node *p = *head;
  if(p->power == power){
    p->coeff += coeff;

    //if coefficient becomes zero then remove it
    if(p->coeff == 0){
      *head = p->next;
      free(p);
    }
    return;
  }
  while(p->next != NULL && p->next->power > power){
    p = p->next;
  }

  //if we get to end node
  if(p->next == NULL){
    if(p->power == power){
      p->coeff +=  coeff;
      if(p->coeff == 0){
        struct Node *ptr = *head;
        while(ptr->next != p){
          ptr = ptr->next;
        }
        free(p);
        ptr->next = NULL;
      }
    }
    else{
      struct Node *newnode = createnode(coeff,power);
      p->next = newnode;
    }
    return;
  }

    if(p->next->power == power){
      p->next->coeff += coeff;

      if(p->next->coeff == 0){
        struct Node *temp = p->next;
        p->next = temp->next;
        free(temp);
      }
    }
    //add betweeen p and p->next
    else{
      struct Node *newnode = createnode(coeff,power);
      newnode->next = p->next;
      p->next = newnode;
    }
}

struct Node* add_polynomial(struct Node *pol1, struct Node *pol2){
  if(pol1 == NULL) return pol2;
  if(pol2 == NULL) return pol1;
  
  struct Node *answer = NULL;
  
  while(pol1 != NULL && pol2 != NULL){
    if(pol1->power == pol2->power){
      add_node(&answer,pol1->coeff+pol2->coeff,pol1->power);
      pol1 = pol1->next;
      pol2 = pol2->next;
    }
    
    else if(pol1->power < pol2->power){
      add_node(&answer,pol2->coeff,pol2->power);
      pol2 = pol2->next;
    }
    
    else{
      add_node(&answer,pol1->coeff,pol1->power);
      pol1 = pol1->next;
    }
  }
  while(pol1 != NULL){
    add_node(&answer,pol1->coeff,pol1->power);
    pol1 = pol1->next;
  }
  while(pol2 != NULL){
    add_node(&answer,pol2->coeff,pol2->power);
    pol2 = pol2->next;
  }
  return answer;
}

struct Node *multiply(struct Node *pol1,struct Node *pol2){
  if(pol1 == NULL) return pol2;
  if(pol2 == NULL) return pol1;
  
  struct Node *answer = NULL;
  
  while(pol1 != NULL){
    struct Node *p = pol2;
    while(p != NULL){
      add_node(&answer,pol1->coeff*p->coeff,pol1->power+p->power);
      p = p->next;
    }
    pol1 = pol1->next;
  }
  return answer;
}
  
void display(struct Node *head){
  if(head == NULL){
    printf("Empty polynomial");
    return;
  }
  
  struct Node *p = head;
  if(p->next == NULL) {
    printf("%.1fx^%d\n",p->coeff,p->power);
    return;
  }
  while(p->next != NULL){
    printf("%.1fx^%d +",p->coeff,p->power);
    p = p->next;
  }
  printf("%.1fx^%d\n",p->coeff,p->power);
}

int main(){
  printf("Enter the number of terms in your polynomial:");
  int terms;
  scanf("%d",&terms);
  
  struct Node *head = NULL;
  
  for(int i=0;i<terms;++i){
    printf("Enter the coefficient:");
    float coeff;
    scanf("%f",&coeff);
    
    printf("Enter the power:");
    int power;
    scanf("%d",&power);
    
    add_node(&head,coeff,power);
  }
  printf("Polynomial you entered is:\n");
  display(head);
  
  
  printf("\nEnter the number of terms in second polynomial:");
  scanf("%d",&terms);
  
  struct Node *head2 = NULL;
  
  for(int i=0;i<terms;++i){
    printf("Enter the coefficient:");
    float coeff;
    scanf("%f",&coeff);
    
    printf("Enter the power:");
    int power;
    scanf("%d",&power);
    
    add_node(&head2,coeff,power);
  }
  printf("Polynomial you entered is:\n");
  display(head2);
  
  struct Node *answer = add_polynomial(head,head2);
  
  printf("\nPolynomial after adding is:\n");

  display(answer);
  
  return 0;
}
    
    
  
  
