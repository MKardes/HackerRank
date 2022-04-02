char* angryProfessor(int k, int a_count, int* a)
{
    char *yey = strdup("YES");
    char *nope = strdup("NO");
    int count = 0;
    int i = 0;
    while (i < a_count)
    {
        if (a[i] <= 0)
            count++;
        i++;
    }
    if (count < k)
        return yey;
    else
        return nope;
}
