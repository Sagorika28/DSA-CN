/* 
You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
Write a program to return true if there exists a sub-array whose sum is zero else, return false.
Sample Input 1 :
6 
7 1 3 -4 5 1
Sample Output 1 :
true
Sample Input 2 :
5 
-6 7 6 2 1
Sample Output 2 :
false 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_set>
using namespace std;

bool zero_sum(int *arr, int n)
{
    unordered_set<int> set;
    int sum = 0;
    // put in the prefix sums into the set
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // If prefix sum is 0 or it is already present
        if ((sum == 0) or (set.find(sum) != set.end()))
        {
            return true;
        }
        set.insert(sum);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    string result;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (result = zero_sum(arr, n) ? "True" : "False");
    return 0;
}