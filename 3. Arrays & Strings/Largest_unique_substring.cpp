/* 
Given a string S, find the largest substring with no repetition
I/P: abcdabceb
O/P: dabce 
*/
// T=O(n) , S=O(k)
#include <iostream>
#include <cstring>
using namespace std;

void find_substr(char *input)
{
    int start = 0, next = 0, lastIndex[256];
    int startOfLongestSubstr = -1;
    int longestSoFar = 0, currentLength = 0;
    char nextChar;
    memset(lastIndex, -1, sizeof(lastIndex));

    while (input[next] != '\0')
    {
        nextChar = input[next];
        if (lastIndex[nextChar] < start) // it hasn't been visited yet since lastIndex[nextChar] here is -1
        {
            next++;
        }
        else
        {
            currentLength = next - start; // shifting the window forward
            if (currentLength > longestSoFar)
            {
                longestSoFar = currentLength;
                startOfLongestSubstr = start;
            }
            start = lastIndex[nextChar] + 1;
            next++;
        }
        lastIndex[nextChar] = next - 1;
    }

    // for considering the leftover block when null is encountered
    currentLength = next - start;
    if (currentLength > longestSoFar)
    {
        longestSoFar = currentLength;
        startOfLongestSubstr = start;
    }

    for (int i = 0; i < longestSoFar; i++)
    {
        cout << input[i + startOfLongestSubstr];
    }
}

int main(int argc, char const *argv[])
{
    char *input = new char[1000];
    cin >> input;
    find_substr(input);
    return 0;
}