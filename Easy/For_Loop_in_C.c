#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	int i;
    i = b - a + 1;
    for (int j = 0; j < i; j++)
    {
        if (a + j <= 9 && a + j >= 1)
        {
            if (a + j == 1)
                printf("one\n");
            else if (a + j == 2)
                printf("two\n");
            else if (a + j == 3)
                printf("three\n");
            else if (a + j == 4)
                printf("four\n");
            else if (a + j == 5)
                printf("five\n");
            else if (a + j == 6)
                printf("six\n");
            else if (a + j == 7)
                printf("seven\n");
            else if (a + j == 8)
                printf("eight\n");
            else
                printf("nine\n");
        }
        else if ((a + j) % 2 == 1)
            printf("odd\n");
        else 
            printf("even\n");
    }
    return 0;
}
