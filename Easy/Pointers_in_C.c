#include <stdio.h>

void update(int *a,int *b) 
{
	int	tmp;
 	
	tmp = *a - *b;
	if (tmp < 0)
		tmp *= -1;
	*a = *b + *a;
	*b = tmp;	
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
