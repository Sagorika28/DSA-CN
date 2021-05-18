/*
Write a program to do basic string compression. For a character which is consecutively repeated more than once,
replace consecutive duplicate occurrences with the count of repetitions.
Example:
Sample Input 1: aaabbccdsa
Sample Output 1: a3b2c2dsa
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string str, new_str = "";
    cin >> str;
    int i = 0, j = i + 1, count = 1, size = str.length();
    while (size--)
    {
        if (str[i] == str[j])
        {
            j++;
        }
        else
        {
            if (count == 1)
                new_str += str[i];
            else
            {
                char ch = (char)(count + '0');
                new_str += str[i];
                new_str += ch;
            }
            i = j;
            j = i + 1;
        }
        count = j - i;
    }
    cout << new_str;
    return 0;
}