/* 
Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
Anagram of a string is a string which is its permutation.
For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
Sample Input 1 :
cde 
abc
Sample Output 1 :
4
Sample Input 2 :
aab
aba
Sample Output 2 :
0 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int  count_del(string s1, string s2)
{
    int count = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < s1.length(); i++)
    {
        map[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        map[s2[i]]--;
    }

    for (auto i : map)  // only the extra elements are counted as they need to be deleted
    {
        count += abs(i.second);  // for counting the absolute difference in case the 2nd string contains characters that are not a part of 1st string (so num becomes -ve then)
    }
    
    return count;
}

int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << count_del(s1, s2);
    return 0;
}