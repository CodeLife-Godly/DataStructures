#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}
void delete_at(struct Node **head,int position){
    if(*head == NULL) return;
    
    struct Node *p = *head;
    if(position == 1){
      while(p->next != *head){
        p = p->next;
      }
      struct Node *temp = p->next;
      p->next = temp->next;
      free(temp);
      *head = p->next;
      return ;
    }
    
    for(int i=0;i<position - 1 && p->next != *head;++i){
      p = p->next;
    }
    if(p->next != *head){
      struct Node *temp = p->next;
      p->next = temp->next;
      free(temp);
    }
    else{
      printf("Position not found\n");
    }
}
void add_end(struct Node **head,int data){
    struct Node *newnode = createnode(data);

    if(*head == NULL){
        newnode->next = newnode;
        *head = newnode;
        return;
    }
    struct Node *p = *head;
    while(p->next != *head){
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
}
void display2(struct Node *head){
    struct Node *p = head;
    for(int i=1;p->next != head;++i){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("%d->(back to %d)\n",p->data,head->data);
}
void bubble_sort(struct Node *head,int length){
    if(head == NULL) return;
    struct Node *p;
    
    for(int i=0;i<length-1;++i){
      int count = 0,swapped = 0;
      p = head;
      do{
        if(p->data > p->next->data){
          int temp = p->data;
          p->data = p->next->data;
          p->next->data = temp;
          swapped = 1;
        }
        p = p->next;
        ++count;
      }while(p != NULL && count < length-i);

      if(!swapped) break;
    }
}
void add_start(struct Node **head,int data){
    struct Node* temp = createnode(data);

    if(*head == NULL){
        *head = temp;
        temp->next = *head;
        return;
    }
    struct Node *p = *head;
    while(p->next != *head){
        p = p->next;
    }
    temp->next = *head;
    *head = temp;
    p->next = temp;
}
void add_at(struct Node **head,int data,int position){
    struct Node* newnode = createnode(data);
    
    if(*head == NULL){
      newnode->next = newnode;
      *head = newnode;
      return;
    }
    if(position == 1){
      struct Node *temp = *head;
      while(temp->next != *head){
        temp = temp->next;
      }
      newnode->next = temp->next;
      temp->next = newnode;
      *head = newnode;
      return;
    }
    struct Node *prev = *head;
    
    for(int i=1;i<position-1 && prev->next != *head;++i){
      prev = prev->next;
    }
    newnode->next = prev->next;
    prev->next = newnode;
}  
void display_circular(struct Node *head,int k){
    struct Node *p = head;
    
    do{
        printf("%d->",p->data);
        int count = k;
        while(count > 0){
            p = p->next;
            --count;
        }
    }while(p != head);
    printf("NULL\n");
}

void display(struct Node *head){
    struct Node *p = head;
    do{
        printf("%d->",p->data);
        p = p->next;
    }while(p!=head);
    printf("NULL\n");
}
void freelist(struct Node *head){
    struct Node  *p = head;

    while(p != NULL){
        struct Node *temp = p;
        free(temp);
        p = p->next;
    }
}
int main(){
    int size;
    printf("Enter the size of list:");
    scanf("%d",&size);
    
    struct Node *head = NULL;
    for(int i=0;i<size;++i){
        int data;
        printf("Enter data:");
        scanf("%d",&data);
        add_end(&head,data);
    }
    printf("Input:");
    display(head);
    
    printf("List after sorting is:\n");
    bubble_sort(head,size);
    display(head);
    freelist(head);

    return 0;
}