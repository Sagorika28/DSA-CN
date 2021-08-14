/* 
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ¬1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 200

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 - 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1   
*/

#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

// Time Complexity: Exponential(O(2^n))
int min_steps_recursive(int n)
{
    if (n == 1)
        return 0;

    int temp = min_steps_recursive(n - 1);
    if (n % 3 == 0)
        temp = min(temp, min_steps_recursive(n / 3));

    if (n % 2 == 0)
        temp = min(temp, min_steps_recursive(n / 2));

    return 1 + temp;
}

// Time Complexity: O(n), as there will be n unique calls. Space Complexity: O(n)
int ms_memoization(int n, int *memo)
{
    // base cases
    if (n == 1)
        return 0;

    if (memo[n] != -1) // if value has been computed already
        return memo[n];

    // calculation
    int temp = ms_memoization(n - 1, memo); // since it will always give a value

    if (n % 3 == 0)
        temp = min(temp, ms_memoization(n / 3, memo));

    if (n % 2 == 0)
        temp = min(temp, ms_memoization(n / 2, memo));

    memo[n] = 1 + temp; // since min was calculated at each step before
    return memo[n];
}

// Time Complexity: O(n), Space Complexity: O(n)
int ms_tabulation(int n)
{
    int *dp = new int[n + 1]();
    dp[1] = 0;
    int temp;
    for (int i = 2; i <= n; i++)
    {
        temp = dp[i - 1];

        if (i % 3 == 0)
            temp = min(temp, dp[i / 3]);

        if (i % 2 == 0)
            temp = min(temp, dp[i / 2]);

        // fill the dp table
        dp[i] = 1 + temp;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    // recursive brute force
    cout << min_steps_recursive(n) << endl;

    // recursive memoization
    int *memo = new int[n + 1];
    memset(memo, -1, sizeof(int) * (n + 1)); // to initialize dynamic arrays since their size isn't fixed
    cout << ms_memoization(n, memo) << endl;
    delete[] memo;

    // tabulation
    cout << ms_tabulation(n);
    return 0;
}