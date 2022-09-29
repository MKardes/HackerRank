#include <stdio.h>

int main()
{
    int count;
    long long sum;
    long tmp;
    scanf("%d",&count);
    while(count > 0)
    {
        scanf("%ld",&tmp);
        sum += tmp;
        count--;
    }
    printf("%llu",sum);
}
