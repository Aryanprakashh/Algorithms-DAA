#include <stdio.h>
#include <stdlib.h>
// 2*i is left child
// 2*i+1 is right child
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int arr[], int n, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int root = i;
    if (left <= n && (arr[left] > arr[root] && arr[left] >= arr[right]))
    {
        swap(&arr[root], &arr[left]);
        heapify(arr, n, 2 * i);
    }
        else if (right <= n && arr[right] > arr[root])
    {
        swap(&arr[right], &arr[root]);
        heapify(arr, n, 2 * i + 1);
    }
    else
        return;
}
void build_max_heap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}
void heapsort(int arr[], int n)
{
    if (n == 1)
        return;
    else
    {
        build_max_heap(arr, n);
        swap(&arr[1], &arr[n]);
        n--;
        heapify(arr, n, 1);
        heapsort(arr, n);
    }
}
int main()
{
    int n;
    printf("Enter size of Array\n");
    scanf("%d", &n);
    int arr[n + 1];
    arr[0] = 0;
    printf("Enter elements of Array\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}