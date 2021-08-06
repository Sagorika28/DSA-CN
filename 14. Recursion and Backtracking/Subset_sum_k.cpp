/* 
Given an integer array A (of length n) and an integer K, find and print all the subsets of input array A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Sample Input:
9
5 12 3 17 1 18 15 3 17
6
Sample Output:
3 3 
5 1   
*/
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;
}

void subsets_helper(int *input, int n, int k, vector<int> &temp)
{
    // base case
    if (n == 0)
    {
        if (k == 0) // subset which sums to k has been found
            print(temp);
        return;
    }

    // include the 1st element
    temp.push_back(input[0]);
    subsets_helper(input + 1, n - 1, k - input[0], temp);

    // don't include the first element
    temp.pop_back();
    subsets_helper(input + 1, n - 1, k, temp);
}

void subsets(int *input, int n, int k)
{
    vector<int> temp;
    subsets_helper(input, n, k, temp);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];
    cin >> k;
    subsets(input, n, k);
    delete[] input;
    return 0;
}