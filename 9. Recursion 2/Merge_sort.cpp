/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/
// T=O(n log n) , S=O(n log n)
#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    int size = end - start + 1;
    int *out = new int[size];
    while (i <= mid and j <= end)
    {
        if (arr[i] <= arr[j])
        {
            out[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            out[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        out[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        out[k] = arr[j];
        j++;
        k++;
    }

    int m = 0;
    // copy out[] into original array arr[]
    for (int i = start; i <= end; i++, m++)
        arr[i] = out[m];

    delete[] out;
}

void merge_sort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    delete[] arr;
    return 0;
}