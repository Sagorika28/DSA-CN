/* 
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz 
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

void remove_dupli(char *str)
{
    if (str[0] == '\0')
        return;

    if (str[0] == str[1])
    {
        int i;
        for (i = 1; str[i] != '\0'; i++)
            str[i - 1] = str[i];
        str[i - 1] = str[i];
        return remove_dupli(str);
    }
    return remove_dupli(str + 1);
}

int main(int argc, char const *argv[])
{
    char str[1000];
    cin >> str;
    remove_dupli(str);
    cout << str;
    return 0;
}