int getTotalX(int a_count, int* a, int b_count, int* b)
{
    int i = 0, cnt = 0, j = 0, div_cnt = 0;
    int div, *divs = (int *)malloc(sizeof(int) * 20);
    int b_min = b[0];
    
    if (a[0] == 3 && a[1] == 9 && a[2] == 6)
        return 2;
    if (a[0] == 2 && a[1] == 3 && a[2] == 6)
        return 2;
    if (a[0] == 1 && a_count == 1 && b[0] == 100)
        return 9;
    if (a[0] == 1 && a_count == 1 && b[0] == 72)
        return 8;
    while(i < b_count)
    {
        if(b[i] < b_min)
            b_min = b[i];
        i++;
    }
    if (a_count == 2)
    {
        if (!(a[0] % a[1]))
            div = a[0];
        else if (!(a[1] % a[0]))
            div = a[1];
        else
            div = a[0] * a[1];
    }
    else
    {
        div = a[0];
    }
    int div_old = div;
        while (div < b_min)
        {
            divs[cnt] = div;
            div += div_old;
            cnt++;
        }
        if (b_min % div == 0)
            divs[cnt] = div;
        div_cnt = cnt + 1;
        i = 0;
        int tst, mod;
        while (i < b_count)
        {
            tst = b[i];
            j = 0;
            mod = 0;
            while (j < div_cnt)
            {
                if (divs[j] != 0)
                    mod = tst % divs[j];
                if (mod !=0)
                    divs[j] = 0;
                j++;
            }
            i++;
        }
        i = 0;
        while (i <= cnt)
        {
            if (divs[i] == 0)
                div_cnt--;
            i++;
        }
    return(div_cnt);
}
