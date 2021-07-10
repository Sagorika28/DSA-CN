/* 
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4 
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

int indices(int *in, int n, int x, int *out)
{
    // base case
    if (n == 0)
        return 0;

    // recursive call
    int size = indices(in, n - 1, x, out);

    // small calc
    if (in[n - 1] == x)
    {
        out[size] = n - 1;
        size++;
    }
    return size;
}

int main(int argc, char const *argv[])
{
    int x, n;
    cin >> n;
    int *in = new int[n], *out = new int[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cin >> x;
    int size = indices(in, n, x, out);
    if (size == 0)
        cout << 0;
    else
    {
        for (int i = 0; i < size; i++)
            cout << out[i] << " ";
    }
    delete[] in;
    delete[] out;
    return 0;
}