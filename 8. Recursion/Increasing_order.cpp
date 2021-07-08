/* 
Print numbers recursively but in the increasing order for a given input n.
Constraints :
1 <= n <= 10000
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
*/
// T=O(n) , S=O(n)
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
        return;

    print(n - 1);
    cout << n << " ";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    print(n);
    return 0;
}