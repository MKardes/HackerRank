int equalizeArray(int arr_count, int* arr)
{
    int equality[1000] = {0};
    int i = 0, max;
    
    while (i < arr_count)
    {
        equality[arr[i]] += 1;
        i++;
    }
    max = equality[0];
    i = 0;
    while (i < 1000)
    {
        if (max < equality[i])
            max = equality[i];
        i++;
    }
    return arr_count - max;
}
