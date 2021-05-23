/* 
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome 
*/
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;

string reverse(string str)
{
    int i, j, size = str.length() - 1;
    char temp;
    for (i = 0, j = size; i <= j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

void reverse_words(string str)
{
    int i = 0;
    string temp = "";
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }

        if (str[i] == ' ' or str[i + 1] == '\0')
        {
            cout << reverse(temp) << " ";
            temp = "";
        }

        i++;
    }
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);

    // reverse whole string
    str = reverse(str);

    // reverse individual words now
    reverse_words(str);
    return 0;
}