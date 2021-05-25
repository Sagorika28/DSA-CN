/* 
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well. 
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int count_pairs(int *arr, int n)
{
    unordered_map<int, int> um;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = -arr[i];
        if (um.find(temp) != um.end())
        {
            count += um[temp];
        }
        um[arr[i]]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << count_pairs(arr, n);
    return 0;
}