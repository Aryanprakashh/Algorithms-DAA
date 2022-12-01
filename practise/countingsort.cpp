#include <iostream>
#include <math.h>
using namespace std;
void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int output[n];      // to store the sorted array
    int count[max + 1]; // to count the frequency of element
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0; // initialiase
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // cumilative sum
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // placing ele at correct position in array
    for (int i = n-1; i >=0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout<<endl;
}
void test()
{
    int arr[] = {192, 214, 5, 21, 4, 5, 74, 732, 235, 52};
    cout<<"Array before Sorting is-->\n";
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr,n);
    countingSort(arr, n);
    cout<<"Array after Sorting-->\n";
    print(arr, n);
}
int main()
{
    test();
}