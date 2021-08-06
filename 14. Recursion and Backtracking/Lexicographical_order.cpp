/* 
Given a number n, print numbers from 1 to n in lexicographical order.
Sample Input:
20
Sample Output:
1 10 11 12 13 14 15 16 17 18 19 2 20 3 4 5 6 7 8 9 
*/
#include <iostream>
using namespace std;

void lex_helper(int n, int i)
{
    if (i > n)
        return;

    cout << i << " ";
    for (int j = 0; j < 10; j++)
        lex_helper(n, 10 * i + j);
}

void lex(int n)
{
    for (int i = 1; i <= 9; i++)
        lex_helper(n, i);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    lex(n);
    return 0;
}