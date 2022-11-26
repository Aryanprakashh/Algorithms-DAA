int findUnique(int *arr, int size)
{
    bool flag = 0;
    int store=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            store = arr[i];
        }
    }
    return store;
}