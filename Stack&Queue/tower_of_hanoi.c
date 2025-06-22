#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1) return;
    stack[++top] = item;
}
int pop(){
    if(top == -1) return 0;
    return stack[top--];
}
void solve(int n,char start,char help,char destination){
    if(n == 1){
        printf("Move from %c to %c\n",start,destination);
        return;
    }
    //follows DFS
    //moved n-1 disks to 'help' from start
    solve(n-1,start,destination,help);
    //now biggest disk (n-th) to destination
    printf("Move from %c to %c\n",start,destination);
    //the n-1 disks in 'help' to destination now
    solve(n-1,help,start,destination);
}

int main(){
    solve(3,'A','B','C');
    return 0;
}