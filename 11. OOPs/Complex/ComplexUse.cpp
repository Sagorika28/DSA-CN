/* 
Input Format :
Line 1 : Two integers - real and imaginary part of 1st complex number
Line 2 : Two integers - real and imaginary part of 2nd complex number
Line 3 : An integer representing choice (1 or 2) (1 represents plus function will be called and 2 represents multiply function will be called)
Output format :
Check details of 'print' function given above.
Sample Input 1 :
4 5
6 7
1
Sample Output 1 :
10 + i12
Sample Input 2 :
4 5
6 7
2
Sample Output 2 :
-11 + i58 
*/
#include <iostream>
#include "ComplexClass.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    int x, y, p, q, choice;
    cin >> x >> y;
    ComplexNumber c1(x, y);

    cin >> p >> q;
    ComplexNumber c2(p, q);

    cin >> choice;

    switch (choice)
    {
    case 1:
        c1.add(c2);
        break;

    case 2:
        c1.multiply(c2);
        break;

    default:
        "Wrong choice entered. Please enter 1 to add or 2 to multiply";
    }

    c1.print();
    return 0;
}