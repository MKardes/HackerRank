char* dayOfProgrammer(int year)
{
    char   *a = strdup("13.09.2017");
    if (1918 == year)
    {
        a[0] = '2';
        a[1] = '6';
    }
    if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        a[1] = '2';
    if (year < 1918 && (year % 4 == 0 || year % 100 == 0))
        a[1] = '2';
    a[6] = year / 1000 + 48;
    a[7] = (year / 100) % 10 + 48;
    a[8] = (year / 10) % 10 + 48;
    a[9] = year % 10 + 48;
    return (a);
}
