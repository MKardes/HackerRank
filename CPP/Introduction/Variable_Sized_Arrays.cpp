#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int i = 0, j = 0;
    int cnt;
    int *aray[n];
    while (i < n)
    {
        scanf("%d",&cnt);
        aray[i] = new int[cnt];
        j = 0;
        while (j < cnt)
        {
            scanf("%d", &aray[i][j]);
            j++;
        }
        i++;
    }
    j = 0;
    while (j < q)
    {
        scanf("%d %d",&n, &i);
        printf("%d\n", aray[n][i]);
        j++;
    }
    return 0;
}
