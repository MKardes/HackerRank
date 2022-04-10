void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges)
{
    int apple = 0;
    int orange = 0;
    int i = 0;
    
    while (i < apples_count)
    {
        if (apples[i] + a >= s && apples[i] + a <= t)
            apple++;
        i++;
    }
    i = 0;
    while (i < oranges_count)
    {
        if (b + oranges[i] <= t && b + oranges[i] >= s)
            orange++;
        i++;
    }
    printf("%d\n%d", apple, orange);
}
