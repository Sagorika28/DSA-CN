/* 
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf 
*/
// T(n) = O(4^n)
#include <iostream>
#include <unordered_map>
using namespace std;

string getString(int dig)
{
    string s;
    switch (dig)
    {
    case 2:
        s = "abc";
        break;

    case 3:
        s = "def";
        break;

    case 4:
        s = "ghi";
        break;

    case 5:
        s = "jkl";
        break;

    case 6:
        s = "mno";
        break;

    case 7:
        s = "pqrs";
        break;

    case 8:
        s = "tuv";
        break;

    case 9:
        s = "wxyz";
        break;

    default:
        s = "";
    }
    return s;
}

void print_kcode(int n, string outputSoFar)
{
    // base case
    if (n == 0)
    {
        cout << outputSoFar << endl;
        return;
    }

    // eliminate the last digit and send its options in the recursive call
    int dig = n % 10;
    n /= 10;
    string options = getString(dig);
    for (int i = 0; i < options.length(); i++)
        print_kcode(n, options[i] + outputSoFar); // append the 3/4 options of the number in the output string
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string outputSoFar = "";
    print_kcode(n, outputSoFar);
    return 0;
}