int minimumNumber(int n, char* password)
{
    int digit[5] = {0};
    int i = 0, j = 0, counter = 0;
    char str[] = "!@#$%^&*()-+";

    if (n < 6)
        digit[0] = 6 - n;
    while (password[i] != '\0')
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            digit[1] = 1;
        if (password[i] >= 'A' && password[i] <= 'Z')
            digit[2] = 1;
        if (password[i] >= '0' && password[i] <= '9')
            digit[3] = 1;
        i++;
    }
    i = 0;
    while (password[i] != '\0')
    {
        while (str[j])
        {
            if (password[i] == str[j])
                digit[4] = 1;
            j++;
        }
        j = 0;
        i++;
    }
    int count = 0;
    j = 1;
    while (j <= 4)
    {
        if (digit[j] == 0)
            count++;
        j++;
    }
    printf("%d, %d",digit[0], count);
    return ((digit[0] > count) ? digit[0] : count);
}
