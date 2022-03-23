
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//First Way
int find_nth_term(int n, int a, int b, int c) 
{
    int  tmp1;
    int  tmp2;
    if (n == 1)
        return(a);
    if (n == 2)
        return (b + a);
    if (n == 3)
        return(a + b + c);
    tmp1 = c;
    tmp2 = b;
    c = a + b + c;
    b = tmp1;
    a = tmp2;
    return(find_nth_term(n - 2, tmp2 , tmp1, c));
}

//Second Way
int find_nth_term(int n, int a, int b, int c)
{
    int  tmp1;
    int  tmp2;
    if (n == 1)
        return(a);
    if (n == 2)
        return (b + a);
    if (n == 3)
        return(a + b + c);
    else
    	return(find_nth_term(n - 1, a, b, c)
		+ find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c));
}


int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
