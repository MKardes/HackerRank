int* permutationEquation(int p_count, int* p, int* result_count)
{
    int *a = (int *)malloc(sizeof(int) * p_count);
    int i = 1, tmp, j, k;
    while (i <= p_count)
    {
        j = 0;
        while (j < p_count)
        {
            if (p[j] == i)
            {
                k = 0;
                while(k < p_count)
                {
                    if (p[k] == j + 1)
                        a[i - 1] = k + 1;
                    k++;
                }
            }
            j++;
        }
        i++;
    }
    *result_count = p_count;
    return a;
}
