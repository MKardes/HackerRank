#include <stdio.h>

int main()
{
    int i = 0, sum1, sum2, count, a[100][100];
    scanf("%d",&count);
    int j = 0;
    while(j < count)
    {
        i = 0;
        while(i < count)
        {
            scanf("%d,",&a[j][i]);
            i++;
        }
        j++;
    }
    i = 0;
    j = 0;
    while (i < count)
    {
        sum1 += a[j][i];
        j++;
        i++;
    }
    i = count - 1;
    j = 0;
    while (j < count)
    {
        sum2 += a[j][i];
        j++;
        i--;
    }
    sum1 = sum1 - sum2;
    if (sum1 < 0)
        sum1 *= -1; 
    printf("%d",sum1);
    return (0);
}
