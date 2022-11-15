#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int l;
        int b;
        int h;
        
    public:
        Box(){
            l = b = h = 0;
        }
        Box(int a1, int b1, int c1){
            l = a1;
            b = b1;
            h = c1;
        }
        Box(Box& B){
            l = B.getLength();
            b = B.getBreadth();
            h = B.getHeight();
        }
        int getLength(){
            return l;
        }
        int getBreadth(){
            return b;
        }
        int getHeight(){
            return h;
        }
        long long CalculateVolume(){
            return (long long)l * b * h;
        }
        bool operator<(Box& B){
            int bl = B.getLength();
            int bb = B.getBreadth();
            int bh = B.getHeight();
            if (l < bl || (l == bl && b < bb) || (l == bl && b == bb && h < bh))
                return true;
            else
                return false;
        }
};
ostream& operator<<(ostream& out, Box& B){
    int l = B.getLength();
    int b = B.getBreadth();
    int h = B.getHeight();
    return out << l << " " << b << " " << h;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
