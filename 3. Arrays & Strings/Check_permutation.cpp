/*
Given two strings, check if they are permutations of each other. Return true or false.
Sample Input:
abac
aacb
Sample Output: ​true
*/
// T=O(n) , S=O(K)
#include <iostream>
#include <cstring>
using namespace std;
int characters[256] = {0}; // frequency array of characters present

bool check_permutation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++)
        characters[str1[i]]++;

    for (int i = 0; i < str2.length(); i++)
        characters[str2[i]]--;

    for (auto i : characters)
    {
        if (i != 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << check_permutation(str1, str2);
    return 0;
}