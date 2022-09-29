int get_min(int *arr, int count)
{
    int min = arr[0];
    int i = 0;
    
    while (i < count)
    {
        if ((arr[i] < min && arr[i] > 0) || (min == 0 && arr[i] > 0))
            min = arr[i];
        i++;
    }
    return min;
}

int* cutTheSticks(int arr_count, int* arr, int* result_count)
{
    int *ar = malloc (sizeof(int) * arr_count);
    int i = 0, k, min, cutten = 0;
    
    while (get_min(arr, arr_count) > 0)
    {
        k = 0;
        min = get_min(arr, arr_count);
        while (k < arr_count)
        {
            if (arr[k] >= min)
            {
                cutten += 1;
                arr[k] -= min;
            }
            k++;
        }
        k = get_min(arr, arr_count);
        ar[i] = cutten;
        cutten = 0;
        i++;
    }
    int *real = malloc(sizeof(int) * (i));
    k = 0;
    while (k < i)
    {
        real[k] = ar[k];
        k++;
    }
    free(ar);
    *result_count = i;
    return real;
}
