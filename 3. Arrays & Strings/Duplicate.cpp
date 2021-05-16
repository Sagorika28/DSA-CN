// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once.
// That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, there is a single integer value that is present twice.
// You need to find and return that duplicate number present in the array.
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;

int find_duplicate(int arr[], int n)
{
    int result = 0;
    // Method 1: O(n*n)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             result = arr[i];
    //             break;
    //         }
    //     }
    // }

    // Method 2: hash maps O(1)

    // Method 3: XOR O(n)
    // Xor all the elements of the array with the elements 0-(n-2). The element with a duplicate gets XORed thrice leading to it.
    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    for (int i = 0; i <= (n - 2); i++)
    {
        result ^= i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int t, n, arr[1000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << find_duplicate(arr, n) << endl;
    }
    return 0;
}