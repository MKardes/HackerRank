int hurdleRace(int k, int height_count, int* height)
{
    int sayac = 0, i = 0;
    int max = height[0];
    while (i < height_count)
    {
        if (max < height[i])
           max = height[i];
        i++;
    }
    return max > k ? max - k : 0;
}
