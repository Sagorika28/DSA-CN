/*
A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).
Implement the Complex numbers class that contains following functions -
1. constructor
You need to create the appropriate constructor.
2. plus -
This function adds two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1
3. multiply -
This function multiplies two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2
4. print -
This function prints the given complex number in the following format :
a + ib
Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.
*/
#include <iostream>
using namespace std;
class ComplexNumber
{
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print()
    {
        cout << real << " + "
             << "i" << imaginary << endl;
    }

    void add(ComplexNumber c)
    {
        real = real + c.real;
        this->imaginary = this->imaginary + c.imaginary; // this->imaginary = imaginary implicity, so this keyword is optional here since the parameter doesn't have the same name as the class attribute
    }

    void multiply(ComplexNumber c)
    {
        // formula : z1z2 = (a + ib)(c + id) = ac + i ad + i bc + i^2 bd = (ac - bd) + i(ad + bc)
        int x = (real * c.real - imaginary * c.imaginary);
        int y = (real * c.imaginary + imaginary * c.real);
        real = x;
        imaginary = y;
    }
};