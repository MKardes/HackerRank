#include <stdio.h>
#include <stdlib.h>

int flatlandSpaceStations(int n, int c_count, int* c)
{
    int    i = 0;
    int    tmp;
    int    tmp1;
    int    max;
    int    j;
    
    max = 0;
    while (i < n)
    {
        j = 0;
        tmp1 = c[0] - i;
        if (tmp1 < 0)
                tmp1 *= -1;
        while (j < c_count)
        {
            tmp = c[j] - i;
            if (tmp < 0)
                tmp *= -1;
            if (tmp1 > tmp)
                tmp1 = tmp;
            j++;
        }
        if (max < tmp1)
            max = tmp1;
        i++;
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int c_cnt;
    scanf("%d", &c_cnt);
    
    int *c = calloc(c_cnt, sizeof(int));
    
    int j = 0;
    while (j < c_cnt)
    {
        int digit;
        scanf("%d", &digit);
        
        c[j] = digit;
        j++;
    }
    
    printf("%d",flatlandSpaceStations(n, c_cnt, c));
    return 0;
}
