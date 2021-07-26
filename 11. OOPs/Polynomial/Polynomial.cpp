/* 
Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
*/
#include <iostream>
#include <cstring>
using namespace std;
class Polynomial
{
public:
    int *degCoeff;
    int capacity;

    // Default Constructor
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        memset(degCoeff, 0, sizeof(degCoeff));
    }

    // Parameterized constructor
    Polynomial(int cap)
    {
        degCoeff = new int[cap];
        capacity = cap;
        memset(degCoeff, 0, sizeof(degCoeff));
    }

    // Copy constructor
    Polynomial(Polynomial const &p2)
    {
        this->degCoeff = new int[p2.capacity];
        for (int i = 0; i < p2.capacity; i++)
        {
            this->degCoeff[i] = p2.degCoeff[i];
        }
    }

    // Copy assignment operator
    void operator=(Polynomial const &p2)
    {
        this->degCoeff = new int[p2.capacity];
        for (int i = 0; i < p2.capacity; i++)
        {
            this->degCoeff[i] = p2.degCoeff[i];
        }
    }

    // print
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i])
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }

    // setCoefficient
    void setCoefficient(int deg, int coeff)
    {
        if (deg < capacity)
            degCoeff[deg] = coeff;

        else
        {
            int newCapacity = capacity;
            while (deg >= newCapacity)
                newCapacity *= 2;

            Polynomial pnew(newCapacity);
            // to make the garbage values 0
            for (int i = 0; i < capacity; i++)
            {
                pnew.degCoeff[i] = this->degCoeff[i];
            }
            // copy new polynomial into the current one after deleting the current one
            delete[] degCoeff;
            degCoeff = pnew.degCoeff;
            capacity = pnew.capacity;
            degCoeff[deg] = coeff;
        }
    }

    // +
    Polynomial operator+(Polynomial const &p2)
    {
        int newcap = max(this->capacity, p2.capacity);

        Polynomial p3(newcap);

        for (int i = 0; i < newcap; i++)
        {
            if (i < capacity && i < p2.capacity)
                p3.degCoeff[i] = this->degCoeff[i] + p2.degCoeff[i];
            else if (i < capacity)
                p3.degCoeff[i] = this->degCoeff[i];
            else
                p3.degCoeff[i] = p2.degCoeff[i];
        }

        return p3;
    }

    // -
    Polynomial operator-(Polynomial const &p2)
    {
        int newcap = max(this->capacity, p2.capacity);

        Polynomial p3(newcap);

        for (int i = 0; i < newcap; i++)
        {
            if (i < capacity && i < p2.capacity)
                p3.degCoeff[i] = this->degCoeff[i] - p2.degCoeff[i];
            else if (i < capacity)
                p3.degCoeff[i] = this->degCoeff[i];
            else
                p3.degCoeff[i] = -p2.degCoeff[i];
        }

        return p3;
    }

    // *
    Polynomial operator*(Polynomial const &p2)
    {
        int newcap = this->capacity + p2.capacity;
        Polynomial p3(newcap);

        for (int i = 0; i < this->capacity; i++)
        {

            for (int j = 0; j < p2.capacity; j++)
            {
                p3.degCoeff[i + j] += this->degCoeff[i] * p2.degCoeff[j];
            }
        }
        return p3;
    }
};