/* 
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array. 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], 
but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, 
as we have to print starting and ending element of the longest consecutive sequence.
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

void sub_long(int arr[], int n, unordered_map<int, bool> um)
{
    int start, max = 0, len, curr, next, prev;
    for (int i = 0; i < n; i++)
    {
        curr = arr[i];
        if (um[curr]) // traverse the array element if it's value is true in the map
        {
            len = 1;
            next = curr + 1;
            // check for the consecutive elements after it
            while (um.find(next) != um.end())
            {
                um[next] = false; // mark as traversed
                len++;
                next++;
            }

            if (len > max)
            {
                max = len;
                start = curr;
            }

            // make curr false in map
            um[curr] = false;
        }
    }

    // If the length of the longest possible sequence is one, then the output array must contain only single element
    if (max == 1)
    {
        cout << arr[0];
    }

    else
    {
        int out[2];
        out[0] = start;
        out[1] = start + max - 1;
        cout << out[0] << " " << out[1];
    }
}

int main(int argc, char const *argv[])
{
    unordered_map<int, bool> um;
    int n, start, max = 0, len, len2, curr, next, prev;
    cin >> n;
    int arr[n];

    // place all the instances of the array into the map
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        um[arr[i]] = true;
    }

    sub_long(arr, n, um);

    return 0;
}