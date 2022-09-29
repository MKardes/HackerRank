int sockMerchant(int n, int ar_count, int* ar)
{
    int a[101] = {0};
    int i = 0, double_chk = 0;
    while (i < ar_count)
    {
        a[ar[i]]++;
        i++;
    }
    i = 0;
    while (i < 101)
    {
        double_chk += a[i] / 2;
        i++;
    }
    return double_chk;
}
