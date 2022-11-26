#include <iostream>
#include <climits>
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

void countsort(int arr[], int n)
{
    int output[n];
    int maxs = max(arr, n);
    int count[maxs];
    for (int i = 0; i < maxs; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    //cumulative sum
    for (int i = 1; i <= maxs; i++)
    {
        count[i] += count[i - 1];
    }
    //storig element in array
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    
}
int main()
{
    int n;
    cout << "Enter size of Array\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}