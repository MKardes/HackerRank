int pageCount(int n, int p)
{
    int begin = 0;
    int last = 0;
    
    if (p % 2 == 0)
        begin = (p - 1) / 2 + 1;
    else
        begin = (p - 1) / 2;
    
    if (n % 2 == 0 && n != p && p % 2 != 0)
        last = (n - p) / 2 + 1;
    else if (n % 2 == 0 && p % 2 != 0)
        last = 0;
    else
        last = (n - p) / 2;
    return ((last > begin) ? begin : last);
}
