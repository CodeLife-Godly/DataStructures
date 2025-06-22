#include <stdio.h>

int sumdiv(int n){
  int sum = 0;
  for(int i=1;i<=n/2;i++){
    if(n%i==0){
      sum += i;  
      }
    }
  return sum;
  }
int perfect(int n){
  int check = sumdiv(n);
  if(check == n){
    return 1;
    }
  else{
    return 0;
    }
  }
int main(){
    int low=0,up = 0;
    printf("Enter lower limit of range:");
    scanf("%d",&low);
    printf("Enter the upper limit of range:");
    scanf("%d",&up);
    for(int i=low;i<=up;i++){
      if(perfect(i)==1){
        printf("%d is perfect number\n",i);
      }
    }
    return 0;
  }
