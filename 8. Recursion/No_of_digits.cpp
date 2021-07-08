/* 
Find out and return the number of digits present in a number recursively.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1
*/
// T=O(log10 n) , S=O(log10 n)
#include <iostream>
using namespace std;

int digits(int n)
{
    // base case
    if (n < 10)
        return 1;

    // small calculation + recursive call
    return 1 + digits(n / 10);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << digits(n);
    return 0;
}