/* 
You are given with two random integer arrays, you have to print their intersection. That is, you have to print all the elements 
that are present in both the given arrays.
For example: If input is: 
 Size1 of arr1 = 6
 arr1[] = 2 6 8 5 4 3
 Size2 of arr2 = 4
 arr2[] = 2 3 4 7
Output: Elements present in both the arrays:
 2
 3
 4 
*/
// T=O((n log n) + (m log m) + (m+n)) , S=O(n)
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void find_intersection(int *arr1, int *arr2, int m, int n)
{
    unordered_map<int, int> um; // um(element, frequency)

    // sort the arrays  --- O((n log n) + (m log m))
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    // store the frequency of occurence of elements of the first array in the hashmap
    for (int i = 0; i < m; i++)
    {
        um[arr1[i]]++;
    }

    // if the element of the 2nd array finds a match in the hashmap, print it
    for (int i = 0; i < n; i++)
    {
        if (um.count(arr2[i]) > 0)
        {
            cout << arr2[i] << " ";

            // decrement the frequency
            um[arr2[i]]--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        find_intersection(arr1, arr2, m, n);
        cout << endl;
    }
    return 0;
}