char* kangaroo(int x1, int v1, int x2, int v2)
{
    char    *yes_no = malloc(sizeof(char) * 7);
    yes_no[0] = 'Y';
    yes_no[1] = 'E';
    yes_no[2] = 'S';
    yes_no[3] = '\0';
    yes_no[4] = 'N';
    yes_no[5] = 'O';
    yes_no[6] = '\0';
    
    int a = 0;
    int diff = x1 - x2;
    if (diff < 0)
    {
        diff *= -1;
        a = 1;
    }
    int diff1 = diff - 1;
    while (diff >= diff1)
    {
        diff = diff1;
        x1 += v1;
        x2 += v2;
        if (x1 == x2)
            return (&yes_no[0]);
        if (a)
            diff1 = x2 - x1;
        else
            diff1 = x1 - x2;
    }
    return (&yes_no[4]);
}
