#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

struct Node* create_node(int info){
    //dynamically allocating memory as this memory is in heap
    //and stays available until program terminates or free() is used
    //unlike the stack (statically allocated memory)
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    //strcture is created or memory is allocated
    newnode->data = info;
    newnode->next = NULL;

    return newnode;
}

void add_first(struct Node** head_ptr,int info){
    struct Node* temp = create_node(info);
    //*temp dereference to structure
    //(*temp).next now refers to attribute of new node created
    (*temp).next = *head_ptr;     //temp is a pointer to node temp
    *head_ptr = temp;        //as head is being changed in place,we need to use a pointer 
}

void display(struct Node* head){
    struct Node* p = head;
    while(p->next != NULL){
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("%d",p->data);
}

void free_linkedlist(struct Node* head){
    while(head!=NULL){
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void add_at(Node **head,int value,int position){
    if(position < 1) return;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;

    if(position == 1){
        newnode->next = *head;
        *head = newnode;
    }
    else{
        Node *temp = *head;
        for(int i=1;i<position-1;++i){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


void delete(Node **head,int value){
    Node *temp = *head,*prev = NULL;
    
    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
    }
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("%d not found\n",value);
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}


int main(){
   struct Node* head = NULL;
    int n;
    printf("Enter the number of elements you want:");
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        int info,position;
        printf("Enter the data of node:");
        scanf("%d",&info);
        add_end(&head,info);
    }
    display(head);

    printf("\nNow where do you want to insert:");
    int position,info;
    scanf("%d",&position);
    printf("Enter the data of node:");
    scanf("%d",&info);

    add_at(&head,position,info);

    printf("Linked list is:\n");
    display(head);
    printf("\nWhere do you want to delete element:");
    int pos;
    scanf("%d",&pos);
    delete_at(&head,pos);
    display(head);

    free_linkedlist(head);

    return 0;
}