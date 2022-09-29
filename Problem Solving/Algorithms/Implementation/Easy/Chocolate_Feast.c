int chocolateFeast(int n, int c, int m)
{
    int a = n / c;
    int cnt = a, tmp, x;
    
    do
    {
        tmp = a / m;
        a = a % m + tmp;
        cnt += tmp;
    } while (tmp > 0);
    return cnt;
}
