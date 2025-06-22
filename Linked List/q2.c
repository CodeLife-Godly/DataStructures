#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char author[30];
    struct Node* next;
};
struct Node* createnode(char* data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->author,data);
    newnode->next = NULL;

    return newnode;
}
void add_start(struct Node **head,char *data){
    struct Node *temp = createnode(data);
    temp->next = *head;
    *head = temp;
}
void add_end(struct Node **head,char *data){
    struct Node* temp = createnode(data);
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
void display(struct Node *head){
   while(head != NULL){
        printf("%s -> ",head->author);
        head = head->next;
    }
    printf("NULL\n");
}
int len(struct Node *head){
    if(head == NULL){
        return 0;
    }
    return 1+len(head->next);
}
void palindrome(struct Node *head){
    int length = len(head),low = 1,i=0;
    struct Node *p,*q = head;

    while(low<length-i){
        int count = 1;
        p = head;

        while(count < length-i){
            p = p->next;
            ++count;
        }
        if(strcmp(p->author,q->author) != 0){
            printf("Not an palindrome\n");
            return;
        }
        q = q->next;
        ++i;
        ++low;
    }
    printf("List forms an palindrome\n");
}
void reverse(struct Node **head){
    struct Node *prev,*now,*after;
    prev = NULL,now = *head,after = (*head)->next;
    //1->2->3->4->5->NULL

    while(now->next != NULL){
        now->next = prev,prev = now,now = after;    
        after = after->next;
    }
    //now is the pointer of last node
    now->next = prev;
    *head = now;  
}
void freelist(struct Node *head){
    while(head!=NULL){
        struct Node *p = head;
        head = head->next;
        free(p);
    }
}
int main(){
    int size;
    printf("Enter the size of list:");
    scanf("%d",&size);
    fgetc(stdin);

    struct Node *head = NULL;
    
    for(int i=0;i<size;++i){
        char info[31];
        printf("Enter author:");
        fgets(info,31,stdin);
        info[strcspn(info,"\n")] = '\0';
        add_end(&head,info);
    }
    printf("The list you entered is:\n");
    display(head);
    printf("The list after reversing is:\n");
    reverse(&head);
    display(head);

    freelist(head);
    return 0;
}