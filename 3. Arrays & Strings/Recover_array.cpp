// We are given an input array such that it stores the middle element taken out one by one from the original array. Recover the original array.
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

void recoverArray(int input[], int n, int output[])
{
    int left, right, mid, i = 0;
    mid = n / 2;

    // if array size is odd, we have to put our 1st element in the mid of the O/P array
    if (n % 2 != 0)
    {
        output[mid] = input[i];
        left = mid - 1;
        right = mid + 1;
        i++;
    }

    // if array size is even, we have no mid element to put, so we start by initializing our left and right of the O/P array
    else
    {
        left = mid - 1;
        right = mid;
    }

    // Put the element to the mid's left and then to mid's right and similarly alternately (i=0 for even array and i=1 for odd array)
    while (i < n)
    {
        output[left] = input[i];
        left--;
        i++;

        output[right] = input[i];
        right++;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int input[1000], output[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    recoverArray(input, n, output);

    for (int i = 0; i < n; i++)
        cout << output[i] << " ";
    return 0;
}