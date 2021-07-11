// Find the length of the given string recursively and also recursively remove all the x's from the string.
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

int length(char str[])
{
    if (str[0] == '\0')
        return 0;

    return 1 + length(str + 1);
}

void removeX(char str[])
{
    if (str[0] == '\0')
        return;

    if (str[0] != 'x')
        return removeX(str + 1);

    else
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
            str[i - 1] = str[i];
        str[i - 1] = str[i]; // to shift the null character forward too
        return removeX(str); // to take care of strings like xxabs->xabc
    }
}

int main(int argc, char const *argv[])
{
    char str[100];
    cin >> str;
    cout << length(str) << endl;
    removeX(str);
    cout << str << endl;
    cout << length(str);
    return 0;
}