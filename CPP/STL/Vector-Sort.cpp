#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int n;
    scanf("%d",&n);
    int j = n;
    while(n > 0)
    {
        int i;
        scanf("%d", &i);
        v.push_back(i);
        n--;
    }
    sort(v.begin(),v.end());
    int i = 0;
    while (i < j)
    {
        cout << v.at(i) <<" ";
        i++;
    }
    return 0;
}
