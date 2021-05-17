// You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively,
// merge them into a third array/list such that the third array is also sorted.
// T=O(m+n) , S=O(m+n)
#include <iostream>
using namespace std;

void merge_arrays(int arr1[], int arr2[], int n, int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n and j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main(int argc, char const *argv[])
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr1[n];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        cin >> m;
        int arr2[m], arr3[n + m];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        merge_arrays(arr1, arr2, n, m, arr3);

        for (int i = 0; i < n + m; i++)
            cout << arr3[i] << " ";

        cout << endl;
    }
    return 0;
}