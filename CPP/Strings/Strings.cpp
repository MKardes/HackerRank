#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    cin >> a >> b;
    cout << a.length() << " " << b.length() << "\n";
    string s = a;
    s.append(b);
    cout << s << "\n";
    
    char tmp;
    tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
    cout << a << " " << b;
  
    return 0;
}
