#include <stdio.h>

void details(int a,int b,int* sum,int* difference,int* product){
    *sum = a+b;
    *difference = a-b;
    *product = a*b;;       
}
int main(){
    int a,b,sum,difference,product;
    printf("Enter first number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    
    int *s = &sum; int *d = &difference ; int *p = &product;
    details(a,b,s,d,p); 
    printf("Sum is:%d\n",*s);
    printf("Difference is:%d\n",*d);
    printf("Product is:%d\n",*p);

    return 0;    
}