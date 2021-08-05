/* 
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12  
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

void subsets_helper(int *input, int n, vector<int> &temp)
{
    // base case
    if (n == 0)
    {
        print(temp);
        return;
    }

    // include the 1st element
    temp.push_back(input[0]);
    subsets_helper(input + 1, n - 1, temp);

    // don't include the first element
    temp.pop_back();
    subsets_helper(input + 1, n - 1, temp);
}

void subsets(int *input, int n)
{
    vector<int> temp;
    subsets_helper(input, n, temp);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];
    subsets(input, n);
    delete[] input;
    return 0;
}