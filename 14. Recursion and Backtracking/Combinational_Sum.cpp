/* 
Given an array of integers A and an integer B. Find and return all unique combinations in A where the sum of elements is equal to B.
Elements of input array can be repeated any number of times.
One combination should be saved in increasing order. Order of different combinations doesn't matter.
Note : All numbers in input array are positive integers.
Input Format :
Line 1 : Integer n
Line 2 : n integers (separated by space)
Line 3 : Integer B (i.e. sum)
Output Format :
Combinations in different lines
Contraints :
1<= N <=1000
Sample Input 1 :
4
7 2 6 5
16
Sample Output 1 :
2 2 2 2 2 2 2 2 
2 2 2 2 2 6 
2 2 2 5 5 
2 2 5 7 
2 2 6 6 
2 7 7 
5 5 6
Sample Input 2 :
4
2 4 6 8
8
Sample Output 2 :
2 2 2 2 
2 2 4 
2 6 
4 4 
8  
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

void print(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void comb_sum(int *a, int b, int n, vector<int> &list, vector<vector<int>> &ans)
{
    // base case 1
    if (b < 0)
        return;

    // base case 2
    if (n == 0) // end of array
        return;

    if (b == 0) // reqd. sum has reached
    {
        ans.push_back(list);
        return;
    }

    // recursive calls
    list.push_back(a[0]);
    comb_sum(a, b - a[0], n, list, ans);

    list.pop_back();
    comb_sum(a + 1, b, n - 1, list, ans);
}

int main(int argc, char const *argv[])
{
    int n, b, num;
    vector<int> list;
    vector<vector<int>> ans;
    unordered_set<int> s;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.insert(num); // remove duplicates
    }

    // alternate way to remove duplicates in a vector:- ar.erase(unique(ar.begin(), ar.end()), ar.end());

    cin >> b;

    int count = 0;
    for (auto ele : s)
        a[count++] = ele;

    //sort the array for ease
    sort(a, a + count);

    comb_sum(a, b, count, list, ans);
    print(ans);

    return 0;
}