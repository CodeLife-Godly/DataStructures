#include <stdio.h>
int main(){
    int n,m;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    m = n/2;

    for(int i=0;i<m;i++){
        for(int k=0;k<2*i;k++){
            printf(" ");
        }
        for(int j=0;j<n-2*i;j++){
            printf("%d ",j+1);
        }
        printf("\n");
    }
    for(int i=0;i<n-m;i++){
        for(int k=2*m;k>2*i;k--){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("%d ",j+1);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}