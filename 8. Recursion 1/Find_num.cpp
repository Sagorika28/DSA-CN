/* 
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false. Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false 
*/
// T=O(n log n) , S=O(n log n)
#include <iostream>
using namespace std;
bool search(int *arr, int start, int end, int x)
{
    if (start > end)
        return false;

    int mid = (start + end) / 2;

    if (arr[mid] == x)
        return true;

    else if (arr[mid] > x)
        return search(arr, start, mid - 1, x);

    else
        return search(arr, mid + 1, end, x);
}

int main(int argc, char const *argv[])
{
    int x, n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    cout << (search(arr, 0, n, x) ? "true" : "false");
    delete[] arr;
    return 0;
}