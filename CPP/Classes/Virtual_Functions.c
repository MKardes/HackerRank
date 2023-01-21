#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int pstat;
static int sstat;

class Person
{
    protected:
        string  name;
        int     age;
        
    public:
        static int get_proffesor()
        {
            pstat++;
            return(pstat);
        }
        static int get_student()
        {
            sstat++;
            return(sstat);
        }
        string get_name(void)
        {
            return (this->name);
        }
        int get_age(void)
        {
            return (this->age);
        }
        void    set_age(int age)
        {
            this->age = age;
        }
        void    set_name(string name)
        {
            this->name = name;
        }
        virtual void getdata()
        {
            cout << "Get data from base!" <<endl;
        }
        virtual void putdata()
        {
            cout << "Put data from base!" <<endl;           
        }
};

class Professor: public Person
{
    private:
        int publications;
        int cur_id;
    public:
        void    getdata()
        {
            cin >> this->name;
            cin >> this->age;
            cin >> this->publications;
            this->cur_id = Person::get_proffesor();
        }
        void    putdata()
        {
            cout << this->name << " ";
            cout << this->age << " ";
            cout << this->publications << " ";
            cout << this->cur_id << endl;
        }
};

class Student: public Person
{
    private:
        int marks[6];
        int cur_id;
    public:
        void    getdata()
        {
            int i = 0;
            cin >> this->name;
            cin >> this->age;
            while(i < 6)
            {
                cin >> this->marks[i];
                i++;
            }
            this->cur_id = Person::get_student();
        }
        void    putdata()
        {
            int i = 0;
            int sum = 0;
            cout << this->name << " ";
            cout << this->age << " ";
            while (i < 6)
            {
                sum += this->marks[i];
                i++;
            }
            cout << sum << " ";
            cout << this->cur_id << endl;
        }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
