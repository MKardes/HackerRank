char* hackerrankInString(char* s)
{
    int i = 0, j = 0;
    char    *hack = "hackerrank";
    char    *a = malloc(7);
    a[0] = 'Y';
    a[1] = 'E';
    a[2] = 'S';
    a[3] = '\0';
    a[4] = 'N';
    a[5] = 'O';
    a[6] = '\0';
    while (s[i])
    {
        if (s[i] == hack[j])
        {
            j++;
            if (hack[j] == '\0')
                return a;
        }
        i++;
    }
    return &a[4];
}
