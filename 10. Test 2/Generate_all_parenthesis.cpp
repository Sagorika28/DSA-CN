/* 
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. 
That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
Input format :
Integer n
Output format :
Print all possible valid parenthesis in different lines
Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.
Constraints :
1 <= n <= 10
Sample Input :
3
Sample Output :
((()))
(()())
(())()
()(())
()()() 
*/
// T=O(2^n)
#include <iostream>
using namespace std;

void make_parenthesis(string str, int n, int open, int close)
{
    if (close == n)
    {
        cout << str << endl;
        return;
    }

    if (close < open)
        make_parenthesis(str + ')', n, open, close + 1);

    if (open < n)
        make_parenthesis(str + '(', n, open + 1, close);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    make_parenthesis("", n, 0, 0);
    return 0;
}