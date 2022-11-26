#include <stdio.h>
#include <stdlib.h>

int cut_rod_recursive(int profit[],int n){
    if(n==0)
    return 0;
    int max_rev=profit[n];
    for (int i = 1; i < n; i++)
    {
        int rec_val=cut_rod_recursive(profit,n-i);
        if(max_rev<profit[i]+rec_val)
        max_rev=profit[i]+rec_val;
    }
    return max_rev;
}
int main()
{
    int n;
    printf("Enter the number of Profir\n");
    scanf("%d", &n);
    int profit[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }
    int ans=cut_rod_recursive(profit,n);
    printf("%d",ans);

}