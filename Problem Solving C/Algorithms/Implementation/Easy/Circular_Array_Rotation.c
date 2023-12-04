int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count)
{
    int c, i = 0, b;
    int *dizi = malloc(sizeof(int) * a_count);
    c = k % a_count;
    while (i < a_count)
    {
        b = i + c;
        if (b >= a_count)
            b = b - a_count;
        dizi[b] = a[i];
        i++;
    }
    int *res = malloc(sizeof(int) * queries_count);
    i = 0;
    while (i < queries_count)
    {
        res[i] = dizi[queries[i]];
        i++;
    }
    free(dizi);
    *result_count = queries_count;
    return res;
}
