/* 
Given an array, find and return the length of longest sub-array containing equal number of 0s and 1s.
Input Format :
Line 1 : Integer N, size of array
Line 2 : Array elements (separated by space)
Output Format :
Length of longest subarray
Contraints :
1<= N <=10^6
Sample Input 1 :
6 
1 0 0 1 1 1
Sample Output 1 :
4    
Sample Input 2 :
10 
1 1 1 0 0 0 1 1 0 0
Sample Output 2 :
10 
*/
// T=O(n) , S=O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int large_subarray(int *arr, int n)
{
    int sum = 0, max_length = 0, len = 0, curr = 0;
    unordered_map<int, int> um; // map(sum_value, index)

    // let the initial sum = 0 be stored at index -1
    um[sum] = -1;

    // taking the sum to be -1 if 0 is encountered and +1 when 1 is encountered
    // whenever cummulative sum becomes 0 or equal to a sum previously seen (since 1 and -1 would cancel each other out), it means that the number of 0's and 1's is equal from (first index of sum to current index)
    for (int i = 0; i < n; i++)
    {
        curr = (arr[i] == 1 ? 1 : -1); 
        sum += curr;
        if (sum == 0 or um.find(sum) != um.end())
        {
            // find the length of the subarray
            len = i - um[sum];
        }

        // if the sum is not previously seen, add it's first occurence (index) in the hashmap
        else
            um[sum] = i;

        // compare with max length till now
        max_length = max(len, max_length);
    }
    return max_length;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << large_subarray(arr, n);

    return 0;
}