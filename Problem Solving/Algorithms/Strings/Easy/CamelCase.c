int camelcase(char* s)
{
    int counter = 1, i = 0;
    while(s[i] != '\0')
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
            counter++;
        i++;
    }
    return counter;
}
