#include <iostream>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 and this->denominator % i == 0)
                gcd = i;
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    Fraction add(Fraction const &f2)
    {
        int x, y;
        int lcm = denominator * f2.denominator;
        x = lcm / denominator;
        y = lcm / f2.denominator;
        int num = (x * numerator + y * f2.numerator);
        Fraction fnew(num, lcm);
        fnew.numerator = num;
        fnew.denominator = lcm;
        fnew.simplify();
        return fnew;
    }

    Fraction multiply(Fraction const &f2)
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }

    // overloading various operators
    // +
    Fraction operator+(Fraction const &f2) const // const since we're not changing the value of 'this->' object
    {
        int x, y;
        int lcm = denominator * f2.denominator;
        x = lcm / denominator;
        y = lcm / f2.denominator;
        int num = (x * numerator + y * f2.numerator);
        Fraction fnew(num, lcm);
        fnew.numerator = num;
        fnew.denominator = lcm;
        fnew.simplify();
        return fnew;
    }

    // *
    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }

    // ==
    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator and denominator == f2.denominator);
    }

    // pre-increment
    Fraction &operator++() // returning a fraction object so that f3=++f1 works, returning through reference so that buffer copy isn't created rather original object is passed
    {
        numerator = numerator + denominator;
        simplify();
        return *this; // return the object having values, pointed by this pointer
    }
};