#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    int a;
    char ch;
    vector<int> v;
    stringstream ss(str);
    
    while (ss >> a)
    {
        v.push_back(a);
        ss >> ch;
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
