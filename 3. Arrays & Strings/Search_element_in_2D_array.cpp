// To search for an element in a 2D matrix which is row-wise and col-wise sorted
// T=O(m+n) , S=O(1)
#include <iostream>
using namespace std;

void find_element(int arr[][100], int m, int n, int x)
{
    // we start from the 1st row and last col and go on till row or col goes out of scope
    int i = 0, j = n - 1;
    while (i <= m - 1 and j >= 0)
    {
        if (x == arr[i][j])
        {
            cout << "Element is at row " << i << " and column " << j;
            return;
        }
        else if (x > arr[i][j])
            i++;
        else
            j--;
    }
    cout << "Element not found!";
}

int main(int argc, char const *argv[])
{
    int arr[100][100], m, n, x;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cin >> x;
    find_element(arr, m, n, x);
    return 0;
}