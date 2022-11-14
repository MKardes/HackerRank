#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, i = 0;
    scanf("%d",&n);
    int arr[n];
    while (i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }   
    i--;
    while(i>=0)
    {
        printf("%d ",arr[i]);
        i--;
    }
    return 0;
}
