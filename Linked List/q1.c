#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}
void InsertStart(struct Node** head,int value){
    struct Node* newnode = createNode(value);
    newnode->next = *head;
    *head = newnode;       //*head points to first node, **head is the pointer
}
void InsertEnd(struct Node **head,int data){
    struct Node* temp = createNode(data);
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
void insert_before(struct Node **head,int value,int x){
    struct Node *temp = createNode(value);
    struct Node *p = *head;

    if(p->data == x){
        temp->next = *head;
        *head = temp;
        return;
    }
    while(p->next->data != x){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}
void insert_after(struct Node** head,int value,int x){
    struct Node *temp = createNode(value),*p = *head;

    while(p->data != x){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}
void InsertAt(struct Node** head,int position,int data){
    struct Node* temp = createNode(data);
    struct Node* p = *head;
    if(position==1){
        temp->next = *head;
        *head = temp;
        return;
    }
    int count = 1;
    while(count < position-1){
        if(p==NULL){
            p = temp;
            return;
        }
        p = p->next;
        count++;
    }
    temp->next = p->next;
    p->next = temp;
}
void reverse(struct Node** head){
    struct Node *ptr = *head,*prev = NULL,*after = (*head)->next;

    while(after != NULL){
        ptr->next = prev;
        prev = ptr;
        ptr = after;
        after = after->next;  //accessing after->next requires after != NULL
    }
    ptr->next = prev;
    *head = ptr;
}
void delete_first(struct Node **head){
    if(*head == NULL){
        printf("Cannot delete from an empty list\n");
        return;
    }
    struct Node *p = *head;
    *head = p->next;
    free(p);
}
void delete_last(struct Node** head){
    if(*head == NULL){
        printf("Cannot delete from an empty list\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *p = *head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}
void delete(struct Node **head,int x){
    if(*head == NULL){
        printf("Can't delete from an empty list\n");
        return;
    }
    if((*head)->data == x){
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* p = *head;
    while(p->next->data != x){
        p = p->next;
        if(p->next == NULL){                   //as we know now last node doesn't have target 
            printf("Element not found\n");     //value from condition in which loop 
            return;
        }
    }
    struct Node *temp = p->next;    //storing information of node to be deleted
    p->next = p->next->next;
    free(temp);
}
void delete_at(struct Node **head,int position){
    struct Node* p = *head;
    if(position == 1){
        struct Node* temp = *head;  //storing address of first node
        *head = (*head)->next;      //changing pointer head to point to second node
        free(temp);         //freeing stored address;
        return;
    }
    int count = 1;
    while(count < position-1){
        if(p==NULL){
            printf("Position is not present in the list.\n");
            return;
        }
        p = p->next;
        ++count;
    }
    struct Node* temp = p->next;
    p->next = temp->next;
    free(temp);
}
void display(struct Node* head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void freelist(struct Node* head){
    struct Node* temp;
    while(head!=NULL){
        temp = head;
        head = (*head).next;
        free(temp);
    }
}
int main(){
    char check;
    struct Node *head = NULL;
    
    printf("To start enter 'y':");
    scanf("%c",&check);
    while(check == 'y'){
        int data,choice;
        printf("Enter these numbers for these operations:\n");
        printf("1 to enter node at start:\n");
        printf("2 to enter node at end:\n");
        printf("3 to enter element before existing node x:\n");
        printf("4 to enter element after existing node x:\n");
        printf("5 to delete first element of list:\n");
        printf("6 to delete the last element:\n");
        printf("7 to delete node x:\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            int x;
            case 1:
                printf("Enter data:");
                scanf("%d",&data);
                InsertStart(&head,data);
                break;
            
            case 2:
                printf("Enter data:");
                scanf("%d",&data);
                InsertEnd(&head,data);
                break;
            case 3:
                printf("Enter data:");
                scanf("%d",&data);
                printf("Enter x:");
                scanf("%d",&x);
                insert_before(&head,data,x);
                break;
            case 4:
                printf("Enter data:");
                scanf("%d",&data);
                printf("Enter x:");
                scanf("%d",&x);
                insert_after(&head,data,x);
                break;
            case 5:
                delete_first(&head);
                break;
            case 6:
                delete_last(&head);
                break;
            case 7:
                printf("Enter x:");
                scanf("%d",&x);
                delete(&head,x);
                break;
            default:
                printf("Invalid number\n");
        } 
        printf("List is:\n");
        display(head);
        printf("If you wish to continue then input 'y':"); 
        scanf(" %c",&check); 
    }
    display(head);
    return 0;
}
