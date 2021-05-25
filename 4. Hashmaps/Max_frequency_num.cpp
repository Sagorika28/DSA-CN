/* 
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int find_max(int *arr, int n)
{
    int max_ele = arr[0], i = 0;
    unordered_map<int, int> um;
    for (i = 0; i < n; i++)
    {
        um[arr[i]]++;
        if (um[arr[i]] > um[max_ele])
        {
            max_ele = arr[i];
        }
    }

    return max_ele;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find_max(arr, n);
    return 0;
}