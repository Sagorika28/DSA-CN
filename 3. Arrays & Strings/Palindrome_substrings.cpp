// Given a string S. Count and return the number of substrings that are palindrome. Single length substrings are also palindromes.
// T=O(n*n) , S=O(1)
#include <iostream>
#include <cstring>
using namespace std;

int count_palindrome(char input[])
{
    int count = 0, length = strlen(input);

    // for odd length substrings, take 1 length mid
    for (int i = 0; i < length; i++)
    {
        int mid = i;
        int left = i - 1, right = i + 1;
        count++; //for single length substrings
        while (left >= 0 and right < length)
        {
            if (input[left] == input[right])
            {
                count++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }

    // for even length substrings, take 2 length mid
    for (int i = 0; i < length - 1; i++)
    {
        int mid1 = i, mid2 = i + 1;
        if (input[mid1] != input[mid2])
        {
            continue;
        }

        int left = mid1 - 1, right = mid2 + 1;
        count++; //for input[mid1] = input[mid2] being a palindrome
        while (left >= 0 and right < length)
        {
            if (input[left] == input[right])
            {
                count++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char str[1000];
    cin >> str;
    cout << count_palindrome(str);
    return 0;
}