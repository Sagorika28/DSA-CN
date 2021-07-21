#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    int age;

public:
    char *name;

    Student(int age, char *name)
    {
        this->age = age;
        // Shallow copy
        // this -> name = name;

        // Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy constructor
    Student(Student const &s)
    {
        this->age = s.age;
        // this -> name = s.name;		// Shallow Copy

        // Deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};
