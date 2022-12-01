// Bottom Up Approach
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 3

int R[N+1][N+1];
int S[N][N];
int top=0;

int MCM(int P[],int i,int j)
{
    for (int length = 2; length <= N; length++)
    {
        for (int k = 1; k <= N-length+1; k++)
        {
            int l=k+length-1;
            for (int m = k; m < l; m++)
            {
                int temp=R[k][m]+R[m+1][l]+P[k-1]*P[m]*P[l];
                // printf("%d\n",temp);
                if(R[k][l] > temp)
                {
                    R[k][l]=temp;
                    S[i][j]=k;
                }
            }
        }
    }
    return R[1][N];
}


int MCMBottomUp(int P[],int i,int j)
{
    for (int k = 0; k < N+1; k++)
    {
        for (int l = 0; l < N+1; l++)
        {
            S[k][l]=0;
            if (l==k)
            {
                R[l][k]=0;
            }
            else
            {
                R[k][l]=100000;
            }
        }
    }
    return MCM(P,i,j);
}

int main()
{
    printf("For %d matrices.\n", N);
    int P[N+1];
    for (int i = 0; i < N+1; i++)
    {
        scanf("%d", P+i);
    }
    printf("Minimum Multiplication is %d.\n", MCMBottomUp(P,1,N));
    return 0;
}

/* 10 5 100 50 */