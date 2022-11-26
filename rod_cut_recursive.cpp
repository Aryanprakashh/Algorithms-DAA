#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}
int rod_cut_recursive(int profit[], int n)
{
    int max_rev = profit[n];
    if (n > 0)
    {
        for (int i = 1; i < n; i++)
        {
            max_rev=max(max_rev,profit[i]+rod_cut_recursive[profit,n-i]);        
        }
    }
    return max_rev;
}
int main()
{

}