/*
You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
Sample Input:
 ​7
0 1 2 0 2 0 1
Sample Output:
 ​0 0 0 1 1 2 2

This problem is a variation of a famous problem called the ‘Dutch National Flag Problem’
*/
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // set a left index to keep track of the position that next 0 should occupy and ||ly a right index for 2's position & start scanning from left
    int left = 0, right, n, i = 0; // store 0 pos, 2 pos and current pos resp.
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    right = n - 1;
    while (i < right) // since all the unsorted elements will lie only between current and right. The ones beyond them are already sorted
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[left]);
            left++; // increment position to where the next 0 is to be placed
            i++;
        }

        else if (arr[i] == 2)
        {
            swap(arr[i], arr[right]);
            right--; // decrement position to where the next 2 is to be be placed
        }

        else
            i++;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}