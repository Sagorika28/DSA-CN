#include <iostream>
using namespace std;
#include "Student.cpp"

int main()
{
    Student s1(101, 30);
    s1.display();
    s1.age = 20;
    s1.display();
}
