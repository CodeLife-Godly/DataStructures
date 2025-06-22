#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node* createnode(int data){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;

    return p;
}
void add_end(struct Node **head,int data){
    struct Node *temp = createnode(data);
    if(*head == NULL){
        *head = temp;
        return;
    }
    struct Node *p = *head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
}
struct Node* concatenate_lists(struct Node *head1,struct Node *head2){
    struct Node *head = NULL;
    while(head1 != NULL){
        add_end(&head,head1->data);
        head1 = head1->next;
    }
    while(head2 != NULL){
        add_end(&head,head2->data);
        head2 = head2->next;
    }
    return head;
}
void delete_alternate_nodes(struct Node *head){
    if(head == NULL){
        printf("Cannot remove nodes from empty list\n");
        return;
    }

    struct Node *temp;
    while(head != NULL && head->next != NULL){
        temp = head->next;
        head->next = temp->next;
        free(temp);
        head = head->next;
    }
}
void display(struct Node* head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void freelist(struct Node *head){
    struct Node *temp;
    while(head != NULL){
        temp = head;
        free(temp);
        head = head->next;
    }
}
int main(){
    int size1,size2;
    printf("Enter the size of list:");
    scanf("%d",&size1);
    
    struct Node *head1 = NULL;

    for(int i=0;i<size1;++i){
        int data;
        printf("Enter data:");
        scanf("%d",&data);

        add_end(&head1,data);
    }
    printf("The list you entered is:\n");
    display(head1);

    printf("After removing alternate nodes:\n");
    delete_alternate_nodes(head1);
    display(head1);

    freelist(head1);
    return 0;
}