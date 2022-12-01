#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n, int pos)
{
    int output[n];
    int count[10];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }
    for (int i = 0; i < max(arr, n); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[((arr[i] / pos) % 10)]-1] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixsort(int arr[], int n)
{
    int maxs = max(arr, n);
    for (int i = 1; maxs / i > 0; i *= 10)
    {
        countsort(arr, n, i);
    }
}
int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Array Before sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    radixsort(arr, n);
    cout<<"Array After sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}