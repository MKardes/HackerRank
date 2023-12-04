int alternatingCharacters(char* s)
{
    int counter = 0, i = 0;
    
    while (*s)
    {
        if ((*s == 'A' && *(s + 1) == 'A') || (*s == 'B' && *(s + 1) == 'B'))
            counter++;
        s++;
    }
    return counter;
}
