int* breakingRecords(int scores_count, int* scores, int* result_count)
{
    *result_count = 2;
    int i = 1;
    static int a[2];
    int max = scores[0], max_cnt = 0;
    int min = scores[0], min_cnt = 0;
    while (i < scores_count)
    {
        if (max < scores[i])
        {
            max = scores[i];
            max_cnt++;
        }
        else if (min > scores[i])
        {
            min = scores[i];
            min_cnt++;
        }
        i++;
    }
    a[0] = max_cnt;
    a[1] = min_cnt;
    return a;
}
