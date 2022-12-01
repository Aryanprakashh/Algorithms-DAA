#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,m;
    printf("Enter no. of letters in string 1 and 2 : ");
    scanf("%d%d",&n,&m);
    char s1[n+1],s2[m+1];
    scanf("%s",s1);
    scanf("%s",s2);
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        arr[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        arr[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else 
            {
                arr[i][j]=arr[i-1][j]>arr[i][j-1]?arr[i-1][j]:arr[i][j-1];
            }
        }
    }
    printf("Common Substring is of Length %d",arr[n][m]);

}

// 7 6 abcbdab bdcaba
// lcs bottom up