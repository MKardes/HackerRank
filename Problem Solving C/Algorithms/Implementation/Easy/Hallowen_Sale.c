int howManyGames(int p, int d, int m, int s)
{
    int sum = 0;
    if (s < p)
        return 0;
    while (s > 0)
    {
        if (p > m && !((s - p) <= 0))
        {
            s -= p;
            p = p - d;
        }
        else if (p <= m)
            s -= m;
        if (s - p < 0 || s - m < 0)
            s = 0;
        sum++;
    }
    return sum ;
}
