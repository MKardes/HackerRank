int utopianTree(int n)
{
    int i = 1, length = 1;
    while (i <= n)
    {
        if (i % 2 == 0)
            length += 1;
        else
            length *= 2;
        i++;
    }
    return length;
}
