/* 
Given an integer n, print all n digit increasing numbers in increasing order in one line.
Numbers you need to print should be in increasing order and only those numbers should be printed which have digits in increasing order.
Input Format :
Integer n
Output Format :
 Numbers in increasing order
Constraints :
1 <= n <= 8
Sample Input :
2
Sample Output :
12 13 14 15 16 17 18 19 23 24 25 26 27 28 29 34 35 36 37 38 39 45 46 47 48 49 56 57 58 59 67 68 69 78 79 89  
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;

bool isValid(int num, int n)
{
    int curr_dig = 0, next_dig;
    next_dig = num % 10;
    num /= 10;
    while (num)
    {
        curr_dig = num % 10;
        if (curr_dig >= next_dig)
            return false;
        num /= 10;
        next_dig = curr_dig;
    }

    return true;
}

void inc(int start, int end, int n)
{
    if (start > end)
        return;

    if (isValid(start, n))
        cout << start << " ";

    inc(start + 1, end, n);
}

int main(int argc, char const *argv[])
{
    int n, start = 1, end;
    cin >> n;
    if (n == 1)
    {
        start = 0;
        end = 9;
    }
    else
    {
        for (int i = 0; i < (n - 1); i++)
            start *= 10;
        end = start * 10 - 1;
    }
    inc(start, end, n);
    return 0;
}