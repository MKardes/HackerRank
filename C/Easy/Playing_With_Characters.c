#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char    ch;
    char    s[100];
    char    sen[100];
    scanf("%[^\n]%*c",&ch);
    scanf("%[^\n]%*c",s);
    scanf("%[^\n]%*c",sen);
    printf("%c\n%s\n%s\n", ch, s, sen);
    return 0;
}
