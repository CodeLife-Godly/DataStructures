#include <stdio.h>
#include <stdlib.h>
#define MEMORY_SIZE 4
#define STACK_UNDERFLOW -9999

int memory[MEMORY_SIZE];
int low = -1;
int high = MEMORY_SIZE;

void push(int choice,int item){
    if(choice == 0){
        if(low+1 == high){
            printf("Stack full\n");
            return;
        }
        memory[++low] = item;
    }
    else if(choice == 1){
        if(high-1 == low){
            printf("Stack full\n");
            return;
        }
        memory[--high] = item;
    }
}

int pop(int choice){
    if(choice == 0){
        if(low == -1){
            printf("Underflow\n");
            return STACK_UNDERFLOW;
        }
        return memory[low--];
    }
    else if(choice == 1){
        if(high == MEMORY_SIZE){
            printf("Underflow\n");
            return STACK_UNDERFLOW;
        }
        return memory[high++];
    }
}
//just write functions, no need to write int main function

int main(){
    push(0,12);
    push(0,23);
    push(1,45);
    push(1,67);
    push(0,34);

    printf("Value of low = %d\n",low);
    printf("Value of high = %d\n",high);
    for(int i = 0;i<MEMORY_SIZE;++i){
        printf("%d\n",memory[i]);
    }
    return 0;
}


