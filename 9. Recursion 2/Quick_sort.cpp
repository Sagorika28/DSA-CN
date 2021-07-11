/* 
Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7  
*/
// T=O(n log n) , S=O(n log n)
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int less_than_pivot = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot) // including the nos. less than and equal to the pivot on the LHS of pivot
            less_than_pivot++;
    }

    int pivot_index = start + less_than_pivot;

    // moving the pivot to the middle
    arr[start] = arr[pivot_index];
    arr[pivot_index] = pivot;

    int i = start, j = end;
    while (i < pivot_index and j > pivot_index)
    {
        if (arr[i] <= pivot)
            i++;

        else if (arr[j] > pivot)
            j--;

        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivot_index;
}

void quick_sort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    delete[] arr;
    return 0;
}