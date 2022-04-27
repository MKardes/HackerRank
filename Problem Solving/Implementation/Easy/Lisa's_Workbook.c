int workbook(int n, int k, int arr_count, int* arr)
{
    int i = 0, page = 1, x, y, res = 0;
    
    while (i < arr_count)
    {
        x = 1;
        while (x <= arr[i])
        {
            if (page == x)
                res++;
            if (x % k == 0 && x != arr[i])
                page++;
            x++;
        }
        page++;
        i++;
    }
    return res;
}
