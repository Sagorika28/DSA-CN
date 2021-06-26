/* Given 2 sorted arrays (in increasing order), find a path through the intersections that produces maximum sum and return the maximum sum.
That is, we can switch from one array to another array only at common elements.
If no intersection element is present, we need to take sum of all elements from the array with greater sum.
*/
// T=O(max(n,m)) , S=O(1)
#include <iostream>
#include <algorithm>
using namespace std;

int max_sum_path(int arr1[], int arr2[], int n, int m)
{
    int max_sum = 0, s1 = 0, s2 = 0, i = 0, j = 0;
    while (i < n and j < m)
    {
        if (arr1[i] < arr2[j])
        {
            s1 += arr1[i];
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            s2 += arr2[j];
            j++;
        }
        else // as soon as they are equal i.e. a common point is reached
        {
            max_sum += max(s1, s2);
            s1 = 0;
            s2 = 0;

            // Keep updating result while there are more common elements
            int temp = i;
            while (i < m && arr1[i] == arr2[j])
                s1 += arr1[i++];

            while (j < n && arr1[temp] == arr2[j])
                s2 += arr2[j++];

            max_sum += max(s1, s2);

            s1 = 0, s2 = 0;
        }
    }
    while (i < n)
    {
        s1 += arr1[i];
        i++;
    }
    while (j < m)
    {
        s2 += arr2[j];
        j++;
    }
    max_sum += max(s1, s2);
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    int arr2[m];
    for (int j = 0; j < m; j++)
        cin >> arr2[j];

    cout << max_sum_path(arr1, arr2, n, m);
    return 0;
}