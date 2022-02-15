/* 
Given a number n, find the no. of nos. greater than n formed using the same digits provided
n has duplicate digits.
*/
#include <iostream>
using namespace std;

int countGreater(int *input, int n, int *fact, int *freq)
{
    if (n == 0 or n == 1)
        return 0;

    int ans = 0, deno = 1;

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
            deno *= fact[freq[i]];
    }

    //iterate over the frequency array
    for (int i = input[0] + 1; i < 10; i++)
    {
        if (freq[i] > 0)
            ans += (fact[n - 1] * freq[i]) / deno;
    }

    // find the combinations of numbers > given no. by recursively calling on the remaining digits except the 1st one
    freq[input[0]]--; // to get rid of the first digit from being included
    ans += countGreater(input + 1, n - 1, fact, freq);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *input = new int[n];
    int *fact = new int[n + 1]; // to store factorials of digits to reduce T(n)
    int freq[10] = {};          // contains frequency of each digit in n
    fact[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        fact[i + 1] = (i + 1) * fact[i];
        freq[input[i]]++;
    }

    cout << countGreater(input, n, fact, freq);
    delete[] input;
    delete[] fact;
    return 0;
}