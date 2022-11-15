#include <iostream>
#include <sstream>
using namespace std;

class Student {
    private:
        int     age;
        string  last_name;
        string  first_name;
        int     standard;
    public:
        void set_age(int num){
            age = num;
        }
        void set_standard(int num){
            standard = num;
        }
        void set_last_name(string st){
            last_name = st;
        }
        void set_first_name(string st){
            first_name = st;
        }
        int get_age(void){
            return age;
        }
        int get_standard(void){
            return standard;
        }
        string get_last_name(void){
            return last_name;
        }
        string get_first_name(void){
            return first_name;
        }
        string to_string(void){
            stringstream ss;
            ss << age << "," << first_name << "," << last_name << "," << standard;
            string str = ss.str();
            return str;
        }
        
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
