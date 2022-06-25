char* extra(char* s, int* x)
{
    int i = 0, minus = 0, j = 0;
    *x = 0;
    while (s[i])
        {
            if (s[i] == s[i + 1])
            {
                s[i] = '-';
                s[i + 1] = '-';
                minus += 2;
                *x = 1;
                i++;
            }
            i++;
        }
        char *a = malloc(sizeof(char) * i - minus + 1);
        i = 0;
        while (s[i])
        {
            if (s[i] != '-')
            {
                a[j] = s[i];
                j++;
            }
            i++;
        }
        if (j == 0)
        {
            free(a);
            return NULL;
        }
        else
            a[j] = '\0';
        free(s);
        return(a);
}

char* superReducedString(char* s)
{
    char *a;
    int x = 1;
    
    while (x == 1)
    {
        a = extra(s, &x);
        if (a == NULL)
            return "Empty String";
        s = a;
        
    }
    return a;
}
