#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}
void add_end(struct Node **head,int data){
    struct Node *temp = createnode(data),*p = *head;
    if(*head == NULL){
       { *head = temp; }
        return;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
}

void display(struct Node *head){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    do{
        printf("%d -> ",head->data);
        head = head->next;
    } while(head != NULL);
    printf("NULL\n");
}
void display_multiples(struct Node *head,int k){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    struct Node *p = head;
    while(p != NULL){
        printf("%d->",p->data);

        int count = k;
        while(p != NULL && count > 0){
            p = p->next;
            --count;
        }
    }
    printf("NULL\n"); 
}
void delete_duplicates(struct Node *head){
    struct Node *current = head;
    if(head == NULL) return;

    while(current != NULL && current->next != NULL){
        struct Node *after = current;
        while(after->next != NULL){
            if(after->next->data == current->data){
                struct Node *duplicate = after->next;
                after->next = duplicate->next;
                free(duplicate); 
            }
            //only move when duplicate is not present in next node
            else{
                after = after->next;
            }
        }
        current = current->next;
    }   
}
struct Node *reverseK(struct Node *head,int k){
    int count = 0;
    struct Node *p = head;
    
    if(head == NULL || k<=1) return head;

    struct Node *prev = NULL,*now = head,*after = head->next;

    while(now != NULL && count < k){
        now->next = prev;
        prev = now;
        now = after;
        if(after != NULL) after = after->next;
        ++count;
    }
    if(now != NULL){
        head->next = reverseK(now,k);
    }
    return prev;   //head of reversed subgroup
}
void reverse(struct Node **head){
    if(*head == NULL) return;
    struct Node *prev = NULL,*now = *head,*after;

    while(now->next != NULL){
        after = now->next;
        now->next = prev;
        prev = now;
        now = after;
    }
    now->next = prev;
    *head = now;
}
void delete(struct Node **head,struct Node *address){
    if(address == NULL || *head == NULL) return;

    if(*head == address){
        struct Node *temp = address;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *p = (*head);
    while(p->next != NULL){
        if(p->next == address){
            struct Node *temp = p->next;
            p->next = temp->next;
            free(temp);
            break;
        }
        p = p->next;
    }
}
void remove_right(struct Node **head,int length){
    struct Node *prev = NULL, *current = (*head)->next;
    int i=0;
    struct Node **array = (struct Node**)malloc(sizeof(struct Node*)*length);

    if((*head)->next->data > (*head)->data){
        array[i] = *head;
        ++i;
    }
    while(current->next != NULL){
        if(current->next->data > current->data){
            array[i] = current;
            ++i;
        }
        current = current->next;
    }
    for(int j=0;j<i;++j){
        delete(head,array[j]);
    }
    free(array);
}
void delete_alternate(struct Node *head){
    if(head == NULL) return;

    while(head != NULL && head->next != NULL){
        struct Node *temp = head->next;
        head->next = temp->next;
        free(temp);
        head = head->next;
    }
}
void pairwise_swap(struct Node *head){
    if(head == NULL) return;

    struct Node *p = head;
    while(p != NULL && p->next != NULL){
        int temp1 = p->data;
        p->data = p->next->data;
        p->next->data = temp1;

        p = p->next->next;
    }
}
void middle(struct Node *head){
    if(head == NULL){
        printf("Empty list\n");
        return;
    } 
    struct Node *p = head;
    int length = 0;

    while(p!=NULL){    
        p = p->next;
        ++length;
    }
    for(int i=0;i<(length/2);++i){
        head = head->next;
    }   
    printf("Middle:%d\n",head->data);
}
struct Node *reversing(struct Node *head){
    if(head == NULL) return head;

    struct Node *prev = NULL,*now = head,*after = head->next;

    while(now->next != NULL){
        now->next = prev;
        prev = now;
        now = after;
        after = after->next;
    }
    now->next = prev;
    return now;
}   
struct Node* copylist(struct Node *head){
    if(head == NULL) return head;

    struct Node *newhead = NULL,*prev = NULL;
    while(head != NULL){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = head->data;
        temp->next = NULL;

        if(newhead == NULL){
            newhead = temp;
            prev = temp;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
        head = head->next;
    }
    return newhead;
}
void palindrome(struct Node *head){
    if(head == NULL) return;

    struct Node *copy = copylist(head);
    struct Node *rev = reversing(copy);

    while(head != NULL && rev != NULL){
        if(rev->data != head->data){
            printf("Not Palindrome\n");
            return;
        }
        rev = rev->next;
        head = head->next;
    }
    printf("Palindrome\n");
}
void frequency(struct Node *head,int size){
    if(head == NULL) return;

    struct Node *p = head,*temp = head;
    int max = head->data;

    while(head != NULL){
        if(head->data > max){
            max = head->data;
        }
        head = head->next;
    }
    int *array = (int*)calloc(max+1,sizeof(int));
    int *printed = (int*)calloc(max+1,sizeof(int));

    while(p != NULL){
        ++array[p->data];
        p = p->next;
    }

    while(temp!=NULL){
        if(!printed[temp->data]){
            printf("Freq(%d)=%d\n",temp->data,array[temp->data]);
            printed[temp->data] = 1;
        }
        temp = temp->next;
    }
    free(array);
    free(printed);
}
void special_add(struct Node *head1,struct Node *head2){
    struct Node *current = head1;
    struct Node *p = head2;
    while(p != NULL && current != NULL){
        //struct Node *temp1 = current->next;
        struct Node *temp = p->next;
        p->next = current->next;
        current->next = p;
        //move on
        if(current->next != NULL){
            current = current->next->next;
        }
        p = temp;
    }
}
void find_pair(struct Node *head,int sum){
    if(head == NULL || head->next == NULL) return ;

    struct Node *outer = head,*inner;
    int test = 0,count = 0;
    while(outer!=NULL){
        test = outer->data;
        inner = outer->next;
        while(inner != NULL){
            if(inner->data == sum - test){
                printf("(%d , %d) ",outer->data,inner->data);
                ++count;
            }
            inner = inner->next;
        }
        outer = outer->next;
    }
    if(!count){
        printf("Pair not found\n");
    }
}
struct Node* reverse_alternate_K(struct Node *head,int k){
    if(head == NULL) return head;

    struct Node *prev = NULL,*now = head,*after = NULL;
        
    int count = 0; 
    while(now != NULL && count < k){
        after = now->next;
        now->next = prev;
        prev = now;
        now = after;
        ++count;
    }
    if(head != NULL){
        head->next = now;
    }
    count = 0;
    while(now != NULL && count < k-1){
        now = now->next;
        ++count;
    }
    if(now != NULL){
        now->next = reverse_alternate_K(now->next,k);
    }
    return prev;
}
void freelist(struct Node *head){
    struct Node *p;
    while(head != NULL){
        p = head;
        free(p);
        head = head->next;
    }
}

int main(){
    int size1;
    printf("Enter the size of list:");
    scanf("%d",&size1);

    struct Node *head = NULL;
    for(int i=0;i<size1;++i){
        int data;
        printf("Enter:");
        scanf("%d",&data);

        add_end(&head,data);
    }
    display(head);
    reverse(&head);
    display(head);
    /* int k;
    printf("Enter k:");
    scanf("%d",&k);

   struct Node *rev = reverse_alternate_K(head,k);
   display(rev);   */
    freelist(head);
    return 0;
}

