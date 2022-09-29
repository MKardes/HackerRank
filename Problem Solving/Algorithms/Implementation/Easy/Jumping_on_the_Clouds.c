int jumpingOnClouds(int c_count, int* c)
{
    int i = 0, res = 0;
    
    while (i < c_count - 2)
    {
        if (c[i] == 0 && c[i + 2] == 0)
            i += 2;
        else if (c[i + 1] == 0 && c[i + 2] == 1)
            i += 1;
        res++;
    }
    if (i + 1 != c_count && c[i + 1] == 0)
        res++;
    return res;
}
