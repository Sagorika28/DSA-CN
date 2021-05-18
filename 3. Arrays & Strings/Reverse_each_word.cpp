/* Code : Reverse each word
Send Feedback
Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".
*/
#include <iostream>
#include <cstring>
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
    reverse_words(str);
    return 0;
}