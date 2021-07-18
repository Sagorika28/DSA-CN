// Create a fraction class and add and multiply 2 fractions
#include <iostream>
#include "FractionClass.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    Fraction f1(3, 4);
    Fraction f2(4, 5);

    // add
    f1.add(f2);
    f1.print();
    f2.print();

    // multiply
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0;
}