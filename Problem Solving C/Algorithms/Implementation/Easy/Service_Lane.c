int* serviceLane(int *width, int n, int cases_rows, int cases_columns, int** cases, int* result_count)
{
    int *a = malloc(sizeof(int) * cases_rows);
    int i = 0, j = 0, min, max;
    while (i < cases_rows)
    {
        j = cases[i][0];
        min = width[j];
        while (j <= cases[i][1])
        {
            if (min > width[j])
                min = width[j];
            a[i] = min;
            j++;
        }
        i++;
    }
    *result_count = cases_rows;
    return a;
}
