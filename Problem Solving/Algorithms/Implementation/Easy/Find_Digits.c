int findDigits(int n)
{
    int tmp = n, mod, cnt = 0;
    while (tmp > 0)
    {
        mod = tmp % 10;
        tmp = tmp / 10;
        if (mod == 0)
            continue;
        mod = n % mod;
        if (!mod)
            cnt++;
    }
    return cnt;
}
