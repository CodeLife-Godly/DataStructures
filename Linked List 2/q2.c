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
void delete_start(struct Node **head){
    if(*head == NULL) return;
    
    struct Node *p = *head;
      while(p->next != *head){
        p = p->next;
      }
      struct Node *temp = p->next;
      p->next = temp->next;
      free(temp);
      *head = p->next;
    
}
void add_end(struct Node **head,int data){
    struct Node *newnode = createnode(data);

    if(*head == NULL){
        newnode->next = newnode;
        {*head = newnode;}
        return;
    }
    struct Node *p = *head;
    while(p->next != *head){
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
}
void bubble_sort(struct Node *head, int length) {
    if (head == NULL) return; 

    struct Node *p;
    
    for (int i = 0; i < length - 1; ++i) {
        int swapped = 0;
        p = head;
        
        for (int count = 0; count < length - i - 1 && p->next != head; ++count) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }

        if (!swapped) break; // If no swaps occurred, the list is already sorted
    }
}

void add_start(struct Node **head,int data){
    struct Node* temp = createnode(data);

    if(*head == NULL){
        *head = temp;
        temp->next = temp;
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
void search(struct Node *head,int value){
    int i = 0;
    struct Node *p = head;
    do{ 
        ++i;
        if(p->data == value){
            printf("%d found at position %d\n",value,i);
            return;
        }
        p = p->next;
    }while(p!=head);
    printf("%d not found\n",value);
}
void update(struct Node *head,int position,int updated){
    struct Node *p = head;
    if(head == NULL) return;

    if(position == 1){
        head->data = updated;
        return;
    }
    int i = 1;
    while(head->next != p && i < position){
        head = head->next;
        ++i;
    }
    head->data = updated;
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
    int choice,t = 1;
    while(t == 1){
    printf("1 to insert at beggining\n2 to insert at end\n3 to delete at start\n4 to display list\n5 to search\n6 to sort\n7 to update list\nAnything else to exit:\n");
    scanf("%d",&choice);

    switch(choice){
        int data;
        case 1:
            printf("Enter data:");
            scanf("%d",&data);
            add_start(&head,data);
            break;
        
        case 2:
            printf("Enter data:");
            scanf("%d",&data);
            add_end(&head,data);
            break;
        
        case 3:
            delete_start(&head);
            break;

        case 4:
            printf("Traversing list:\n");
            display(head);
            break;
        
        case 5:{
            int value;
            printf("Enter value to search:");
            scanf("%d",&value);
            search(head,value);
            break;
        }
        case 6:
            printf("Sorting list\n");
            bubble_sort(head,size);
            break;
            
        case 7:{
            int value,pos;
            printf("Enter position to update:");
            scanf("%d",&pos);
            printf("Enter updated value:");
            scanf("%d",&value);

            update(head,pos,value);
            break;
        }
        default:
            printf("Invalid input\n");
        }
        printf("1 to continue,else to exit\n");
        scanf("%d",&t);
    }
    freelist(head);
    return 0;
}