#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int	sum;

    scanf("%d", &n);
    if (n >= 10000 && n <= 99999)
    {
   	 sum = 0;
	 while (n > 0)
	 {
		 sum += n % 10;
		 n /= 10;
	 }
    }
    printf("%d",sum);
    return 0;
}
