#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int     a;
    int     b;
    int     tmp;
    float   c;
    float   d;
    float   temp;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%f",&c);
    scanf("%f",&d);
    
    tmp = a + b;
    a = a - b;
    temp = c + d;
    c = c - d;
    
    printf("%d %d\n%.1f %.1f", tmp, a, temp, c);
    return 0;
}
