#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* createnode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}
void add_at(struct Node **head,int position,int data){
    struct Node *p = *head;
    struct Node *newnode = createnode(data);

    int count = 1;
    while(p!=NULL && count != position-1){
        ++count;
        p = p->next;
    }
    newnode->next = p->next;
    newnode->prev = p;
    p->next->prev = newnode;
    p->next = newnode;
}
int max(struct Node *head){
    if(head == NULL) return -1;
    int res = head->data;
    while(head != NULL){
        if(res < head->data){
            res = head->data;
        }
        head = head->next;
    }
    return res;
}
void delete_end(struct Node *head){
    if(head == NULL) return;
    while(head->next != NULL){
        head = head->next;
    }
    head->prev->next = NULL;
    free(head);
}
void display(struct Node *head){
    int count = 1;
    while(head != NULL){
        printf("Node %d:%d\n",count,head->data);
        head = head->next;
        ++count;
    }
}
void freelist(struct Node *head){
    while(head!=NULL){
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    int size;
    printf("Enter number of nodes (3 or more):");
    scanf("%d",&size);

    struct Node *head = NULL,*p = NULL;

    for(int i=0;i<size;++i){
        int data;
        printf("Input data for node %d:",i+1);
        scanf("%d",&data);
        
        struct Node *temp = createnode(data);

        if(head == NULL){
            head = temp;
            p = head;
        }
        else{
            temp->prev = p;
            p->next = temp;
            p = p->next;
        }
    }
    printf("Data entered in the list are:\n");
    display(head);
/*
    int pos1,pos2;
    if(size % 2 == 0){
        pos1 = size/2;
        pos2 = size/2 + 1;
    }
    else{
        pos1 = pos2 = (size+1)/2;

    } 
    int pos1 = (size%2 == 0) ? size/2 : (size+1)/2;
    int pos2 = (size%2 == 0) ? size/2 + 1 : (size+1)/2;
    printf("Input position (%d to %d) to insert a node:",pos1,pos2);
    */
    printf("Maximum in linked list:%d\n",max(head));
    freelist(head);
    return 0;
}