/* 
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer. Do this recursively.
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints :
1 <= x <= 30
0 <= n <= 30
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32 
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

double pow(int x, int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    double out = (double)(x * pow(x, n - 1));
    return out;
}

int main(int argc, char const *argv[])
{
    int x, n;
    cin >> x >> n;
    cout << pow(x, n);
    return 0;
}