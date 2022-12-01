#include<stdio.h>

int max(int a,int b){
    return (a>b?a:b);
}

int rod_cut(int profit[],int result[],int n){
    result[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            result[i]=max(max(profit[i],result[i]),result[j]+result[i-j]);
        }
    }
    return result[n];
}

int main(){
    int n;
    printf("Enter total size of rod : ");
    scanf("%d",&n);
    int profit[n+1],result[n+1];
    printf("Enter profit of rods of respective sizes : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&profit[i]);
        result[i]=0;
    }
    printf("Maximum profit is %d",rod_cut(profit,result,n));
}