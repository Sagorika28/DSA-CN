//T=O(n)
#include <iostream>
using namespace std;

int fibr(int n, int *arr)
{
    if (n == 0 or n == 1)
        return 1;

    if (arr[n] > 0) // previously calculated
        return arr[n];

    int output = fibr(n - 1, arr) + fibr(n - 2, arr);
    arr[n] = output; // store output for further use
    return output;
}

int fibi(int n)
{
    int *arr = new int[n + 1]();
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    int output = arr[n];
    delete[] arr;
    return output;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n + 1]();
    cout << "Fibonacci using recursion and DP = " << fibr(n, arr) << endl;
    delete[] arr;
    cout << "Fibonacci using iteration = " << fibi(n);
    return 0;
}