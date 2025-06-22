#include <stdio.h>
#include <stdlib.h>

//node for tree
struct Node{
    int info;
    struct Node *lchild,*rchild;
};
typedef struct Node TreeNode; 

typedef struct QueueNode{
    struct Node* treenode; //stores pointer to tree's node
    struct QueueNode* next;
}QueueNode;

//creating a queue
typedef struct Queue{
    struct QueueNode *front,*rear;  
}Queue;

TreeNode* createnode(int info){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->info = info;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

QueueNode *createQueueNode(TreeNode *node){
    if(node == NULL) return NULL;

    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treenode = node;
    temp->next = NULL;
    return temp;
}

void enqueue(Queue* q,TreeNode* node){
    QueueNode *temp = createQueueNode(node);

    if(q->rear == NULL){
        q->rear = q->front = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

TreeNode* dequeue(Queue *q){
    if(q->front == NULL) return NULL;

    QueueNode *oldFront = q->front;
    TreeNode *temp = oldFront->treenode;    //value to be removed
    q->front = q->front->next;

    if(q->front == NULL){
        //now queue is empty
        q->front = q->rear = NULL;
    }
    free(oldFront);
    return temp;
}  

int isEmpty(Queue* q){
    if(q->front == NULL) return 1;
    return 0;
}

void LevelOrder(TreeNode *root){
    Queue q = {NULL,NULL};

    if(root == NULL){
        printf("Empty tree\n");
        return;
    }
    enqueue(&q,root);
    while(!isEmpty(&q)){
        TreeNode *node = dequeue(&q);
        printf("%d ",node->info);
        if(node->lchild) enqueue(&q,node->lchild); 
        if(node->rchild) enqueue(&q,node->rchild);
    }
    printf("\n");
}

int main(){
    TreeNode *root = NULL;
    //level 1
    root = createnode(30);
    //level 2
    root->lchild = createnode(5);
    root->rchild = createnode(2);
    //level 3
    root->lchild->lchild = createnode(20);
    root->lchild->rchild = createnode(30);
    root->rchild->lchild = createnode(6);
    root->rchild->rchild = createnode(7);
    //level 4
    root->lchild->lchild->lchild = createnode(99);

    printf("Level Order traversal:");
    LevelOrder(root);

    return 0;
}


