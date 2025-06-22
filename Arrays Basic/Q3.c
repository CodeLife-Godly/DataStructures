#include <stdio.h>

int sumnum(int n){
  int sum = 0;
  while(n>0){
    sum += n%10;
    n = n/10;
    }
  return sum;
  }

int sum_recursive(int n,int sum){
  if(n==0){
    return sum;
    }
  sum_recursive(n/10,sum+n%10);
}

int main(){
  int num;
  printf("Enter the number:");
  scanf("%d",&num);
  printf("Using recursive function, sum is:%d\n",sum_recursive(num,0));
  printf("Without using recursive function,sum is:%d\n",sumnum(num));
  return 0;
  }