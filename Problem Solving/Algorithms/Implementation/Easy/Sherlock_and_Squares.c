int if_square(int a)
{
    int x = 1;
    while (x <= a)
    {
        if ((x * x) == a)
            return 1;
        x++;
    }
    return 0;
}

int squares(int a, int b)
{
    int res = 0;
    while (a <= b)
    {
        if (if_square(a))
            res++;
        a++;
    }
    return res;
}
