int* gradingStudents(int grades_count, int* grades, int* result_count)
{
    *result_count = grades_count;
    int i = 0;
    int *a = malloc(sizeof(int) * grades_count);
    
    while (i < grades_count)
    {
        if (grades[i] >= 38 && grades[i] % 5 >= 3)
            a[i] = grades[i] + 5 - (grades[i] % 5);
        else
            a[i] = grades[i];
        i++;
    }
    printf("%d,%d,%d,%d",a[0],a[1],a[2],a[3]);
    return a;
}
