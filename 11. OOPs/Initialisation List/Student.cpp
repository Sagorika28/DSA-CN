// We create initialisation lists to initialise the constant and reference variables (can initialise other vars too) since they can only be initialised once during creation
#include <iostream>
using namespace std;
class Student 
{
public:
    const int rollNo; // can be initialised here but then each object will have the same rollNo
    int age;
    int &x; // reference variable for age

    // parameterized constructor : initialisation list
    Student(int r, int age) : rollNo(r), age(age), x(this->age) {} 

    void display()
    {
        cout << "Roll no: " << rollNo << endl;
        cout << "Age: " << age << endl;
        cout << "Reference x value: " << x << endl;
    }
};