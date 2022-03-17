#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

void get_binary(int i, int j, int *and, int *or, int *xor)
{
    int a[8] = {0};
    int b[8] = {0};
    int i_tmp, j_tmp, div;
    printf("\nFor %d and %d result:\n",i,j);
    div = 0;
    i_tmp = i;
    while (i_tmp > 0)
    {
        i_tmp /= 2;
        div ++;
    }
    a[8 - div] = 1;
    int g = 0;
    while (g < 8)
        printf("%d, ",a[g++]);
    printf("\n");
}

void calculate_the_maximum(int n, int k) {
    int i = 1;
    int j = 1;
    int and, or, xor;
    while (i < n)
    {
        j = 1;
        while(j < k)
        {
            get_binary(i, j, &and, &or, &xor);
            j++;
        }
        i++;
    } 

}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

