/* 
Check recursively to find whether guven array is sorted or not.
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

bool is_sorted(int *arr, int n)
{
    // base case
    if (n == 0 or n == 1)
        return true;

    // calculation
    if (arr[0] > arr[1])
        return false;

    // recursive call on smaller array
    return is_sorted(arr + 1, n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << (is_sorted(arr, n) ? "True" : "False");
    delete[] arr;
    return 0;
}