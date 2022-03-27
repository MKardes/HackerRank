#include <stdio.h>

int main()
{
    int a[3], b[3];
    int i = 0;
    int alice = 0;
    int bob = 0;
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    scanf("%d%d%d", &b[0], &b[1], &b[2]);
    while(i < 3)
    {
        if (a[i] > b[i])
            alice++;
        else if (a[i] < b[i])
            bob++;
        i++;
    }
    printf("%d %d",alice, bob);
    return (0);
}
