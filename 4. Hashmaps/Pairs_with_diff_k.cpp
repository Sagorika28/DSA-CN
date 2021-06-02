/* 
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Sample Input 1 :
4           -- n
5 1 2 4     -- elements
3           -- k
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int count_pairs(int arr[], int n, int k)
{
    unordered_map<int, int> um;
    int count = 0, curr, next, prev;

    for (int i = 0; i < n; i++)
    {
        curr = arr[i];
        next = arr[i] + k;
        prev = arr[i] - k;
        if (um.find(next) != um.end())
        {
            count += um[next];
        }

        if (k != 0 and (um.find(prev) != um.end())) // if k = 0, then we should not count the pairs twice
        {
            count += um[prev];
        }
        um[curr]++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    int arr[n];

    // place all the instances of the array into the map
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    cout << count_pairs(arr, n, k);
    return 0;
}