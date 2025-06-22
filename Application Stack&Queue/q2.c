#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
//only for single digits 

char arr[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1){
        printf("Overflow\n");
        return;
    }
    arr[++top] = item;
}

char pop(){
    if(top == -1){
        printf("Underflow\n");
        return '\0';
    }
    return arr[top--];
}

void reverse(char *str){
    int low = 0;
    int high = strlen(str)-1;
    while(low<high){
        char temp = str[low];
        str[low] = str[high];
        str[high] = temp;

        ++low;
        --high;
    }
}

int main(){
    printf("Enter the expression:");
    char *str = (char*)malloc(sizeof(char)*MAX);
    fgets(str,MAX,stdin);
    str[strcspn(str,"\n")] = '\0';

    //reversing expression
    reverse(str);

    for(int i = 0;i<strlen(str);++i){
        if(isdigit(str[i])){
            push(str[i]);
        }
        else{
            int temp1 = pop()-'0';
            int temp2 = pop()-'0';
            int result;
            switch(str[i]){
                case '+': result = temp1+temp2; break;
                case '-': result = temp1-temp2; break;
                case '*': result = temp2*temp1; break;
                case '/': result = temp1/temp2; break;
                default:
                    printf("Invalid operator:%c\n",str[i]);
                    return 0;
            }
            push(result+'0');
        }
    }
    printf("Output is: %d\n",pop()-'0');
    return 0;
}
