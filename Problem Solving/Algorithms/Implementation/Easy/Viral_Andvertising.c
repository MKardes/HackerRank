int viralAdvertising(int n)
{
    int a = 5, cnt = 0;
    
    while (n > 0)
    {
        a = a / 2;
        cnt += a;
        a = a * 3;
        n--;
    }
    return (cnt);
}
