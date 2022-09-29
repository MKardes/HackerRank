int* stones(int n, int a, int b, int* result_count)
{
    int i, x, max = n - 1, max1 = n - 1, c = 0, m = 0, tmp;
    int *arr = malloc(sizeof(int) * 10000);

    if (a == b)
    {
        free(arr);
        arr = malloc(sizeof(int) * 1);
        max1 = 0;
    }
    else if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (c <= max1)
    {
        i = 0;
        m = 0;
        max = n - 1 - c;
        while (i < n - 1)
        {
            if (max > 0)
                m += a;
            else
                m += b;
            i++;
            max--;
        }
        arr[c] = m;
        c++;
    }
    if (a == b)
        n = 1;
    *result_count = n;
    return arr;
}
