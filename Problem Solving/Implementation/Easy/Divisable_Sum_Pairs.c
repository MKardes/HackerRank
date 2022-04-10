int divisibleSumPairs(int n, int k, int ar_count, int* ar)
{
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n)
    {
        j = n - 1;
        while (j > i)
        {
            if ((ar[i] + ar[j]) % k == 0)
                cnt++;
            j--;
        }
        i++;
    }
    return (cnt);
}
