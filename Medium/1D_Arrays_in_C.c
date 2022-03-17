#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 0;
    int n, d, sum = 0;
    scanf("%d",&n); 
    while (i < n)
    {
        scanf("%d",&d);
        sum += d;
        i++;
    }
    printf("%d",sum);
    return 0;
}
