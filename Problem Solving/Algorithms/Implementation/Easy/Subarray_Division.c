int birthday(int s_count, int* s, int d, int m)
{
    int i = 0, j = 0;
    int cnt = 0, tmp = 0;
    while (i < s_count)
    {
        j = i;
        tmp = 0;
        while (j - i < m)
        {
            tmp += s[j];
            j++;
        }
        if (tmp == d)
            cnt++;
        i++;
    }
    return (cnt);
}
