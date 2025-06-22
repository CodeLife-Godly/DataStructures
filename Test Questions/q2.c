#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node* next;
};

struct Pair{
    struct Node *head;
    struct Node *tail;
};

struct Node *createnode(int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->info = data;
    newnode->next = NULL;

    return newnode;
}

void add_start(struct Node **head,int value){
    struct Node *temp = createnode(value);
    if(*head == NULL){
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

struct Pair rotateRightGroup(struct Node *head,int k){
    struct Pair result;
    if(!head || k ==1){
        result.head = head;
        result.tail = NULL;
        return result;
    }

    struct Node *prev = NULL;
    struct Node *curr = head;

    for(int i=0;i<k-1;++i){
        prev = curr;
        curr = curr->next;
    }
    //curr = last node
    //prev = second last node 
    struct Node *last = curr;
    
    prev->next = NULL;   
    last->next = head;

    result.head = last;
    result.tail = prev;

    return result;
}

struct Node *rotate_K(struct Node *head,int k){
    if(!head || k <= 1) return head;

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = head;
    struct Node *prevGroup = temp;
    struct Node *ptr = head;

    while(ptr != NULL){
        //atleast k nodes ahead
        struct Node *p = ptr;
        int count = 0;
        while(p != NULL && count < k){
            ++count;
            p = p->next;
        }
        if(count < k) break;
        //isolate group and save pointers
        struct Node *groupStart = ptr;
        struct Node *groupEnd = ptr;

        for(int i=0;i<k-1;++i){
            groupEnd = groupEnd->next;
        }
        //groupEnd is the last node

        //saving
        struct Node *nextGroup = groupEnd->next;

        //isolate
        groupEnd->next = NULL;

        struct Pair group = rotateRightGroup(groupStart,k);
        //connect prevGroup to head of rotated
        prevGroup->next = group.head;
        //connect rotated group to nextGroup
        group.tail->next = nextGroup;

        //increment
        prevGroup = group.tail;
        ptr = nextGroup;
    }
    head = temp->next;
    free(temp);
    return head;
}

void display(struct Node *head){
    while(head != NULL){
        printf("%d->",head->info);
        head = head->next;
    }
    printf("NULL\n");
}


void Rotate_K(struct Node *head,int k){
    struct Node *ptr = head,*p;
    int value,temp,last;
    while(ptr!=NULL){
        value = ptr->info;
        p = ptr;
        for(int i=1;i<k && p!=NULL;++i){
            p = p->next;
        }
        if(p == NULL){
            return;
        }
        else{
            last = p->info;
        }
        p = ptr;
        //count has to be k
        for(int i=1;i<k;++i){
            temp = value;
            ptr = ptr->next;
            value = ptr->info;
            ptr->info = temp;
        }
        //value = 3
        p->info = last;
        ptr = ptr->next;
    }
}


int main(){
    int nodes;
    struct Node *head = NULL;
    printf("Number of nodes:");
    scanf("%d",&nodes);
    for(int i = 0;i<nodes;++i){
        int data;
        printf("Enter:");
        scanf("%d",&data);
        add_start(&head,data);
    }
    printf("List:");
    display(head);
    printf("Enter K:");
    int k;
    scanf("%d",&k);
    struct Node *newlist = rotate_K(head,k);
    display(newlist);
    return 0;
}