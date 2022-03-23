#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char    a[1000];
    int     b[10] = {0};
    scanf("%[^\n]%*c",a);
    int i = 0;
    while (a[i])
    {
        if (a[i] == '0')
            b[0] += 1;
        else if (a[i] == '1')
            b[1] += 1;
        else if (a[i] == '2')
            b[2] += 1;
        else if (a[i] == '3')
            b[3] += 1;
        else if (a[i] == '4')
            b[4] += 1;
        else if (a[i] == '5')
            b[5] += 1;
        else if (a[i] == '6')
            b[6] += 1;
        else if (a[i] == '7')
            b[7] += 1;
        else if (a[i] == '8')
            b[8] += 1;
        else if (a[i] == '9')
            b[9] += 1;
        i++;
    }
    i = 0;
    while (i <= 9)
        printf("%d ",b[i++]);
    return 0;
}
