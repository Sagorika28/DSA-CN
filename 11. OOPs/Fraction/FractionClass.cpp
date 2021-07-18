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
            if (numerator % j == 0 and denominator % j == 0)
                gcd = i;
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    void add(Fraction const &f2)
    {
        int x, y;
        int lcm = denominator * f2.denominator;
        x = lcm / denominator;
        y = lcm / f2.denominator;
        int num = (x * numerator + y * f2.numerator);
        numerator = num;
        denominator = lcm;
        simplify();
    }

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
};