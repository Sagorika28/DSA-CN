/*
You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros that are present 
in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.
Sample Input 1:
1
7
2 0 0 1 3 0 0
Sample Output 1:
2 1 3 0 0 0 0
*/
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;

void push_zeros_to_end(int *arr, int n)
{
    int non_zero_pos = 0, i = 0;
    while (i < n)
    {
        if (arr[i] != 0) // increment non-0 position when a non-0 number is encountered after swapping it with the front element
        {
            swap(arr[i], arr[non_zero_pos]);
            non_zero_pos++;
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int t; // store 0 pos, 2 pos and current pos resp.
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        push_zeros_to_end(arr, n);

        cout << "Resultant array: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    return 0;
}