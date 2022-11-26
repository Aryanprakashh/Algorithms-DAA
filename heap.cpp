#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// heapify function
void heapify(int arr[], int i, int n)
{
    if (2 * i <= n && (arr[i] < arr[2 * i] && arr[2 * i] >= arr[2 * i + 1]))
    {
        swap(&arr[i], &arr[2 * i]);
        heapify(arr, 2 * i, n);
    }
    else if ((2 * i + 1<= n) && (arr[i]) < arr[2 * i + 1])
    {
        swap(&arr[i], &arr[2 * i + 1]);
        heapify(arr, 2 * i + 1, n);
    }
    else
        return;
}
/// buil heap max function
void max_heap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }
}
// to create a max heap by rearrarging elements using heapify;

void heapsort(int arr[], int n)
{
    max_heap(arr, n);

    for (int i = 1; i <=n; i++)
    {
        swap(&arr[1], &arr[n]);
        n = n - 1;
        heapify(arr, 1, n);
    }
}
int main()
{
    int n;
    cout << "Enter size of Array\n";
    cin >> n;
    int arr[n + 1];
    arr[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];

    }

    heapsort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}