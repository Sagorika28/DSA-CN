/* 
Given two arrays (both of size n), one containing arrival time of trains and other containing the corresponding trains departure time 
(in the form of an integer) respectively. Return the minimum number of platform required, such that no train waits.
Arrival and departure time of a train can't be same.
Sample Input 1 :
6                                      - 6 trains
900 940 950 1100 1500 1800             - arrival times
910 1200 1120 1130 1900 2000           - departure times
Sample Output 1 :
3
*/
// T=O(n log n) , S=O(1)
#include <iostream>
#include <algorithm>
using namespace std;

int count_platforms(int *arr, int *dept, int n)
{
    // sort the arrival and departure arrays
    sort(arr, arr + n);
    sort(dept, dept + n);

    // keep i to track arrival times and j to track the departure times of trains
    int i = 1, j = 0, max_platforms = 1, needed_platforms = 1;
    while (i < n and j < n)
    {
        if (arr[i] <= dept[j]) // if next train arrives before the previous train leaves i.e. If the arrival time is less than or equal to departure then one more platform is needed
        {
            max_platforms++;
            i++;
        }
        else if (arr[i] > dept[j]) // Else if the arrival time greater than departure then one less platform is needed so decrease the count
        {
            max_platforms--;
            j++;
        }
        if (needed_platforms < max_platforms)
            needed_platforms = max_platforms;
    }
    return needed_platforms;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int *dept = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        cin >> dept[i];

    cout << count_platforms(arr, dept, n);
    return 0;
}