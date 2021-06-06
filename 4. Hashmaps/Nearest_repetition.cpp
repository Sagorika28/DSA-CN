/* 
Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
Input Format :
Line 1 : Integer N, Size of array
Line 2 : Elements of the array (separated by space)
Output Format :
Print the minimum distance 
Contraints :
1<= N <=10^6
Sample Input 1:
6
1 3 1 5 4 3
Sample Output 1:
2
Sample Input 2:
7
5 47 82 4 4 6 2 
Sample Output 2:
1 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int min_dist(int *arr, int n)
{
    int min_d = INT_MAX, dist;
    unordered_map<int, int> um; // um(num, index)
    for (int i = 0; i < n; i++)
    {
        if (um.find(arr[i]) != um.end())
        {
            dist = i - um[arr[i]];
        }
        um[arr[i]] = i;
        min_d = min(min_d, dist);
    }
    return min_d;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << min_dist(arr, n);
    return 0;
}