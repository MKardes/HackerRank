int marsExploration(char* s)
{
    int i = 0, counter = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] != 'S')
            counter++;
        if (s[i + 1] != 'O')
            counter++;
        if (s[i + 2] != 'S')
            counter++;
        i += 3;
    }
    return counter;
}
