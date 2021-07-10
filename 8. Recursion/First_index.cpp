/* 
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
1 
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

int first_index(int *arr, int n, int x)
{
    if (n == 0)
        return -1;

    if (arr[0] == x)
        return 0;

    int ans = first_index(arr + 1, n - 1, x);
    if (ans == -1)
        return -1;
    else
        return ans + 1;
}

int main(int argc, char const *argv[])
{
    int x, n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << first_index(arr, n, x);
    delete[] arr;
    return 0;
}