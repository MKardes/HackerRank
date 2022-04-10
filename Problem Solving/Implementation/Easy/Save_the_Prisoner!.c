int saveThePrisoner(int n, int m, int s)
{
    if (n - s + 1 >= m)
        return (s + m - 1);
    else
        return (((m - (n - s + 1)) % n == 0) ? n : (m - (n - s + 1)) % n);
}
