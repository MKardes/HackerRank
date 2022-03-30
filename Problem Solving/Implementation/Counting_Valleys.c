int countingValleys(int steps, char* path)
{
    int i = 0;
    int valley_cnt = 0;
    int sea_level = 0;
    
    while (i < steps)
    {
        if (path[i] == 'U' && sea_level == -1)
        {
            valley_cnt++;
            sea_level++;
        }
        else if (path[i] == 'U')
            sea_level++;
        else
            sea_level--;
        i++;
    }
    return valley_cnt;
}
