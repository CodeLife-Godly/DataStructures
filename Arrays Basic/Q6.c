#include <stdio.h>
int is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
void Prime(int n){
    int x = n;
    if(n<=1){
        printf("Enter a valid number,greater than 1");
    }
    else{
        for(int i=2;i<=x;i++){
            if(i>n){
                break;
            }
            if(is_prime(i)==1){
                if(n%i==0){
                    printf("%d ",i);
                }
                while(n%i==0){
                    n = n/i;
                }
            }
        }
    }
    return;
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    Prime(n);
    return 0; 
}