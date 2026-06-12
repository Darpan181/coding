#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int rno;
    float marks;
    Student(string n, int r, float m){ // CONSTRUCTOR
        name= n;
        rno= r;
        marks= m;
    }
};
int main()
{
    Student s("Darpan", 18, 98.3);
    cout<< s.name;
return 0;
}