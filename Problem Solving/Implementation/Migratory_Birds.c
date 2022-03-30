int migratoryBirds(int arr_count, int* arr)
{
    int i = 0;
    int ret_value = 0, max = 0;
    int ar[124992] = {0};
    while (i < arr_count)
    {
        ar[arr[i]] += 1;
        i++;
    }
    i = 0;
    while (i < arr_count)
    {
        if (max <= ar[i])
        {
            max = ar[i];
            if (ar[ret_value] != max)
                ret_value = i;
        }
        i++;
    }
    return ret_value;
}
