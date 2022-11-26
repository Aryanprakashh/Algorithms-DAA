#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}

int rod_cut(int profit[], int n, int result[])
{
    result[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            result[i] = max(max(result[i], profit[i]), result[j] + profit[i - j]);
        }
    }
    return result[n];
}
int main()
{
}