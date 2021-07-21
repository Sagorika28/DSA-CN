#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction const f3; // making the object constant so we can't alter any of it's properties

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl; // can be called since they are constant member functions

    // f3.setNumerator(10); // can't be called as it's not constant
}