#include <stdio.h>

void to_hexa(int n){
    if(n<=0){
        return;
    }
    to_hexa(n/16);
    if(n%16>9){
        printf("%c",55+n%16);
    }
    else{
        printf("%d",n%16);
    }
}
void convert(int n,int base){
    if(n<=0){
        return;
    }
    convert(n/base,base);
    printf("%d",n%base);
}
int main(){
    int num,base;

    printf("Enter the number in decimal:");
    scanf("%d",&num);
    
    printf("Enter the base in which you want to convert:");
    scanf("%d",&base);
    if(base==16){
        to_hexa(num);
    }
    else{
        convert(num,base);
    }
    return 0;
}