/* 
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of n n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample n:
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
// T(n) = O(n)
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

int kcode(int n, string *output)
{
    // base case
    if (n == 0 or n == 1)
    {
        output[0] = "";
        return 1; // null character's length is returned
    }

    // recursive call
    int dig = n % 10;
    int ron = n / 10;
    int ron_size = kcode(ron, output);

    // calculation
    string options = getString(dig);

    // make extra copies
    for (int i = 0; i < options.size() - 1; i++) // eg. to make 2 extra copies if 3 options are there
    {
        for (int j = 0; j < ron_size; j++)
            output[j + (i + 1) * ron_size] = output[j];
    }

    //  concatenate the first number's 3 letters with the returned substrings
    int k = 0;
    for (int i = 0; i < options.size(); i++)
    {
        for (int j = 0; j < ron_size; j++)
        {
            output[k] = output[k] + options[i];
            k++;
        }
    }

    return ron_size * options.size(); // since after copying the strings with the 1st letter, size would be twice the original
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string *output = new string[100000000]; // creating a string array
    unordered_map<int, char[]> um;

    int count = kcode(n, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << endl;
    return 0;
}