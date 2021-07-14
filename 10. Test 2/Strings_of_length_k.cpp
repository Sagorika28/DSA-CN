/* 
Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
The characters can repeat as many times as needed.
Note : The number of output strings can be at max 1000.
Input format :
String S and Integer k (separated by space)
Output Format :
All possible strings (in different lines)
Constraints :
1 <= Length of String S <= 10
1 <= k <= 5
Sample Input 1 :
abc 2
Sample Output 1 :
aa
ab
ac
ba
bb
bc
ca
cb
cc 
*/
// T=O(n^k)
#include <iostream>
using namespace std;

void print(string str, string outputSoFar, int k)
{
    if (k == 0)
    {
        cout << outputSoFar << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string new_op;
        new_op = outputSoFar + str[i];
        print(str, new_op, k - 1);
    }
}

int main(int argc, char const *argv[])
{
    int k, n;
    string str;
    cin >> str >> k;
    string outputSoFar = "";
    print(str, outputSoFar, k);
    return 0;
}