#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 60

struct Node{
  int id;
  char name[51],dept[41],des[41],phno[11];
  float sal;
  
  struct Node *next,*prev;
};

struct Node *createnode(int id,char* name,char* dept,char* des,char* phno,float sal){
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  
  newnode->id = id;
  strcpy(newnode->name,name);
  strcpy(newnode->dept,dept);  
  strcpy(newnode->des,des);
  newnode->sal = sal;
  strcpy(newnode->phno,phno);
  newnode->next = NULL;
  newnode->prev = NULL;
  
  return newnode;
}
void input(int* id,char* name,char* dept,char* des,char* phno,float* sal){
    printf("Enter id:");
    scanf("%d",id);
    fgetc(stdin);

    printf("Enter name:");
    fgets(name,51,stdin);
    name[strcspn(name,"\n")] = '\0';

    printf("Enter department:");
    fgets(dept,41,stdin);
    dept[strcspn(dept,"\n")] = '\0';

    printf("Enter designation:");
    fgets(des,41,stdin);
    des[strcspn(des,"\n")] = '\0';

    printf("Enter phone number:");
    fgets(phno,11,stdin);
    phno[strcspn(phno,"\n")] = '\0';

    printf("Enter salary:");
    scanf("%f",sal);
    fgetc(stdin);
  }

void add_end(struct Node** head,int id,char* name,char* dept,char* des,char* phno,float sal){
  struct Node *temp = createnode(id,name,dept,des,phno,sal);
  
  struct Node *p = *head;
  if(*head == NULL){
    *head = temp;
    return;
  }
  while(p->next != NULL){
    p = p->next;
  }
  //now p is the last node
  temp->prev = p;
  p->next = temp;
}
void add_start(struct Node** head,int id,char* name,char* dept,char* des,char* phno,float sal){
    struct Node *temp = createnode(id,name,dept,des,phno,sal);

    if(*head == NULL) {
      *head = temp;
      return;
    }
    
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
  }
void insertion(struct Node **head,int id,char* name,char* dept,char* des,char* phno,float sal,int x){
  struct Node *p = *head;
  
  while(p->id != x){
    p = p->next;
  }
  struct Node *temp = createnode(id,name,dept,des,phno,sal);
  temp->next = p->next;
  p->next->prev = temp;
  p->next = temp;
  temp->prev = p;
}
void delete_end(struct Node **head){
  if(*head == NULL) return;

  struct Node *p = *head;
  while(p->next != NULL) p = p->next;
  //p is now last node
  p->prev->next = NULL;
  free(p);
}
void max_min(struct Node *head){
  if(head == NULL) return;

  float min = head->sal, max = head->sal;
  struct Node *p = head;

  while(p!=NULL){
    if(p->sal > max) max = p->sal;

    if(p->sal < min) min = p->sal;
    
    p = p->next;
  }
  printf("Maximum salary:%.1f\n",max);
  printf("Minimum salary:%.1f\n",min);
}
void delete_start(struct Node **head){
  if(*head==NULL) return;

  struct Node *p = *head;

  *head = p->next;
  if(*head != NULL){
    (*head)->prev = NULL;
  }
  free(p);
}
void deletion(struct Node **head,int x){
  if(*head == NULL) return;

  struct Node *p = *head;
  while(p->id != x){
    p = p->next;
  }
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);
  }
void display(struct Node *head){
  int length = 0;
  while(head!=NULL){
    ++length;
    printf("Employee %d:\n",length);
    printf("ID = %d\nName = %s\nDepartment = %s\nDesignation = %s\nPhone No.= %s\nSalary = %.1f\n",head->id,head->name,head->dept,head->des,head->phno,head->sal);
    head = head->next;
  }
  printf("Number of nodes:%d\n",length);
}
int main(){
  struct Node *head = NULL;
  int choice,t = 1;
  while(t == 1){
  printf("Enter 1 if you want to insert and 2 if you want to delete:");
  scanf("%d",&choice);
  
  if(choice == 1){
    char name[51],dept[41],des[41],phno[11];
    int id;
    float sal;
    
    int choice2;
    
    printf("1 to create List of N employees:\n");
    printf("2 to display status of List and return length of list:\n");
    printf("3 to perform insertion at end:\n");
    printf("4 to perform insertion at start:\n");
    printf("5 to insert after given id of employee:\n");
    scanf("%d",&choice2);
    
    switch(choice2){
      case 1 : {
        int N;
        printf("Enter N:");
        scanf("%d",&N);
        for(int i=0;i<N;++i){
            input(&id,name,dept,des,phno,&sal);
            add_end(&head,id,name,dept,des,phno,sal);
        }
        break;
      }
      case 2:
        printf("Staus of List is:\n");
        display(head);
        break;
      
      case 3:
        input(&id,name,dept,des,phno,&sal);
        add_end(&head,id,name,dept,des,phno,sal);
        break;
      
      case 4:
        input(&id,name,dept,des,phno,&sal);
        add_start(&head,id,name,dept,des,phno,sal);
        break;
      
      case 5:{
        int x;
        printf("Enter the id to insert:");
        scanf("%d",&x);
        input(&id,name,dept,des,phno,&sal);
        insertion(&head,id,name,dept,des,phno,sal,x);
        break;
      }
    
      default : 
        printf("Wrong input\n");
    }
}
  else if(choice == 2){
    int choice2;
    printf("Enter 1 to delete in front:\n");
    printf("Enter 2 to delete at end:\n");
    printf("Enter 3 to delete particular employee after a given Id: \n");

    scanf("%d",&choice2);

    switch(choice2){
      case 1:
        delete_start(&head);
        break;
      
      case 2:
        delete_end(&head);
        break;
      
      case 3:{
        printf("Enter id:");
        int x;
        scanf("%d",&x);
        deletion(&head,x);

        break;
      }
      default:
        printf("Wrong input\n");
    }
  }
  else{
    printf("Enter valid choice\n");
  }
  printf("Enter 1 to continue , else to exit:");
  scanf("%d",&t); 
}
  max_min(head);
  return 0;
}
    
    
  
  
  


