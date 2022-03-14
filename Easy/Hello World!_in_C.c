#include <stdio.h>

int main() 
{
    char   s[50];
    scanf("%[^\n]%*c",s);

    printf("Hello, World!\n");
    printf("%s",s);
    return (0);
}
