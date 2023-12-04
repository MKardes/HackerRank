int beautifulTriplets(int d, int arr_count, int* arr)
{
    int cnt = 0, i = 0, j, k;
    
    while (i < arr_count)
    {
        j = i;
        while (j < arr_count)
        {
            if (arr[j] - arr[i] == d)
                break;
            j++;
        }
        k = j;
        while (k < arr_count)
        {
            if (arr[k] - arr[j] == d)
            {
                cnt++;
                break;
            }
            k++;
        }
        i++;
    }
    return cnt;
}
