/* 
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)
Output Format :
Updated string
Constraints :
1 <= Length of String S <= 10^6
Sample Input :
abacd
a x
Sample Output :
xbxcd 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <cstring>
using namespace std;

void replace(char str[], char c1, char c2)
{
    if (str[0] == '\0')
        return;

    if (str[0] == c1)
        str[0] = c2;

    return replace(str + 1, c1, c2);
}

int main(int argc, char const *argv[])
{
    char str[1000000];
    char c1, c2;
    cin >> str;
    cin >> c1 >> c2;
    replace(str, c1, c2);
    cout << str;
    return 0;
}