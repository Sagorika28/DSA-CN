/* 
Given two strings string1 and string2 (named large and small), find the smallest substring in string1 containing all characters of string2 in O(n). You need to return the output substring.
Note : The characters of string2 need not to be present in same order in string1. That is, we need a substring which contains all characters of string2 irrespective of the order.
Return null if no substring with all characters is present.
Input format :
Line 1 : String 1
Line 2 : String 2
Output Format :
Smallest substring
Constraints :
1 <= Length of string1 & string2 <= 10^4
Sample Input 1 :
Looks for minimum string
mums
Sample Output 1 :
mum s
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
// T=O(m+n) , S=O(1)
#include <iostream>
#include <cstring>
using namespace std;

string find_substr(string s, string t)
{
    if (t.length() > s.length())
    {
        return "";
    }

    int str[256] = {0}; // stores occurence of s
    int pat[256] = {0}; // stores occurence of t

    int i, j, count = 0, min_len = INT_MAX, len = 0, start = 0, first = -1;

    // add all the characters of t in the frequency array
    for (i = 0; i < t.length(); i++)
    {
        pat[t[i]]++;
    }

    for (j = 0; j < s.length(); j++)
    {
        // add the character occurence of the string s in  str[] i.e. increase char freq
        str[s[j]]++;

        // if the character freq of a char in s matches (<=) the one in t, increase the count
        if (str[s[j]] <= pat[s[j]])
            count++;

        // if count = t's length, try to minimize the window size by moving start forward if
        // 1. char doesn't occur in t's freq array
        // 2. char's freq in str[] > char's freq in pat[] i.e. we have additional characters and it can be skipped
        if (count == t.length())
        {
            while (pat[s[start]] == 0 or str[s[start]] > pat[s[start]])
            {
                if (str[s[start]] > pat[s[start]])
                    str[s[start]]--;

                // increase start to shrink the window
                start++;
            }

            len = j - start + 1;
            // update the window size
            if (min_len > len)
            {
                min_len = len;
                first = start;
            }
        }
    }

    // if no window is found, return NULL
    if (first == -1)
    {
        return "";
    }

    // else return the subtring
    return s.substr(first, min_len);
}

int main(int argc, char const *argv[])
{
    // using 2 pointer sliding window approach
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << find_substr(s, t);
    return 0;
}