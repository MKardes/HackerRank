#include <stdio.h>

int main()
{
    int n, n1;
    int sum = 0;
    
    scanf("%d",&n);
    while (n > 0)
    {
        scanf("%d",&n1);
        sum += n1;
        n--;
    }
    printf("%d",sum);
}
