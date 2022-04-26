int dst_find(int *a, int a_count, int idx)
{
    int dst = -1, i = idx + 1;
    while (i < a_count)
    {
        if (a[i] == a[idx])
            return i - idx;
        i++;
    }
    return dst;
}

int minimumDistances(int a_count, int* a)
{
    int i = 0, dst = -1, tmp;
    
    while (i < a_count)
    {
        tmp = dst_find(a, a_count, i);
        if (dst == -1 && tmp != -1)
            dst = tmp;
        else if (tmp != -1 && dst > tmp)
            dst = tmp;
        i++;
    }
    return dst;
}
