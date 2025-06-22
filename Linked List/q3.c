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

void add_start(struct Node **head,int data){
    struct Node *temp = createnode(data);
    if(*head == NULL){
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
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
void remove_duplicates(struct Node *head){
    struct Node* temp;
    while(head->next != NULL){
        if(head->data == head->next->data){
            temp = head->next;
            head->next = temp->next;
            free(temp);
        }
        else{
            head = head->next;
        }
    }
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
void concatenate(struct Node *head1,struct Node *head2){
    struct Node *p = head1,*q = head2;

    while(p->next != NULL){
        p = p->next;
    }
    //p points to last node of head1
    while(q != NULL){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;

        p->next = temp;
        p = temp;
        q = q->next;
    }
}
void reverse(struct Node **head){
    if(*head == NULL){
        return;
    }
    struct Node *prev = NULL,*now = *head,*after = now->next;

    while(now->next != NULL){
        now->next = prev;
        prev = now;
        now = after;
        after = after->next;
    }
    now->next = prev;
    *head = now;
}
void display(struct Node* head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    int size1,size2;
    printf("Enter the size of list:");
    scanf("%d",&size1);
    
    struct Node *head1 = NULL,*head2 = NULL;

    for(int i=0;i<size1;++i){
        int data;
        printf("Enter data:");
        scanf("%d",&data);

        add_end(&head1,data);
    }
    printf("The list you entered is:\n");
    display(head1);

    printf("Enter the size of list:");
    scanf("%d",&size2);

    for(int i=0;i<size2;++i){
        int data;
        printf("Enter data:");
        scanf("%d",&data);

        add_end(&head2,data);
    }
    printf("The list you entered is:\n");
    display(head2);

    printf("Concatenating both lists:\n");
    //struct Node* head = concatenate_lists(head1,head2);
    concatenate(head1,head2);
    display(head1);
    printf("The list in reverse is:\n");
    reverse(&head1);
    display(head1);
    return 0;

}