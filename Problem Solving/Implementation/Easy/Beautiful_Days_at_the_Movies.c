int beautifulDays(int i, int j, int k)
{
    int rev = 1, tmp, cnt = 0, dif;
    
    while (i <= j)
    {
        rev = 0;
        tmp = i;
        while (tmp > 0)
        {
            if (rev != 0)
                rev *= 10;
            rev += tmp % 10;
            tmp /= 10;
        }
        dif = rev - i;
        if (dif < 0)
            dif *= -1;
        if (dif % k == 0)
            cnt++;
        i++;
    }
    return (cnt);
}
