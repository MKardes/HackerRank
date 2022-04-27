long repeatedString(char* s, long n)
{
    long i = 0, c = 0, b;
    long res = 0;
    while (s[i])
    {
        if (s[i] == 'a')
            c++;
        i++;
    }
    b = n / i;
    res = b * c;
    b = n % i;
    i = 0;
    while (i < b)
    {
        if (s[i] == 'a')
            res++;
        i++;
    }
    return res;
}
