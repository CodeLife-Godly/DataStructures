#include <stdio.h>

void to_binary(int n){
    if(n<=0){
        return;
    }
    to_binary(n/2);
    printf("%d",n%2);
}
int main(){
    int num;
    printf("Enter the number whose binary equivalent you want:");
    scanf("%d",&num);
    printf("Binary equivalent is:");
    to_binary(num);
    return 0;
}