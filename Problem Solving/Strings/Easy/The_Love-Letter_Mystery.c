int theLoveLetterMystery(char* s)
{
    int i = 0, j = 0, k, counter = 0;
    
    while (s[j] != '\0')
        j++;
    j--;
    k = (j + 1) / 2;
    while (i < k)
    {
        while (s[i] != s[j])
        {
            if (s[i] > s[j])
                s[i]--;
            else if (s[i] < s[j])
                s[j]--;
            counter++;
        }
        i++;
        j--;
    }
    return counter;
}
