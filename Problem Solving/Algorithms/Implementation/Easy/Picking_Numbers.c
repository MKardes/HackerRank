int pickingNumbers(int a_count, int* a)
{
    int s[100] = {0};
    int i = 0, max = 0;
    while (i < a_count)
    {
        s[a[i]]++;
        i++;
    }
    i = 0;
    i = 0;
    while (i < 99)
    {
        if (max < s[i] + s[i + 1])
            max = s[i] + s[i + 1];
        i++;
    }
    return max;
}
