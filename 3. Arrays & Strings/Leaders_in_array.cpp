/* 
Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, 
if all the elements following it (i.e. present at its right) are less than or equal to A[i]. 
Sample Input 1 :
6
3 12 34 2 0 -1
Sample Output 1 :
34 2 0 -1
*/
// T=O(n) , S=O(1)
#include <iostream>
#include <vector>
using namespace std;

vector<int> find_leaders(vector<int> arr, int n)
{
    vector<int> out;
    out.push_back(arr[n - 1]);
    int max = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            out.insert(out.begin(), arr[i]);
            max = arr[i];
        }
    }
    return out;
}

int main(int argc, char const *argv[])
{
    int n, element;
    cin >> n;
    vector<int> arr(n);
    vector<int> out(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    out = find_leaders(arr, n);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}