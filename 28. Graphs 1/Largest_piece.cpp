/* 
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3 
*/

#include <iostream>
using namespace std;

int dfs(int **cake, int n, bool **vis, int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= n)
        return 0;

    if (cake[i][j] != 1)
        return 0;

    if (vis[i][j])
        return 0;

    vis[i][j] = true;

    int count = 0;
    count += dfs(cake, n, vis, i, j - 1);
    count += dfs(cake, n, vis, i - 1, j);
    count += dfs(cake, n, vis, i, j + 1);
    count += dfs(cake, n, vis, i + 1, j);

    return 1 + count;
}

int pieces(int **cake, int n)
{
    bool **vis = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = new bool[n];
        for (int j = 0; j < n; j++)
            vis[i][j] = false;
    }

    int count = 0, maxm = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                count = dfs(cake, n, vis, i, j);
                maxm = max(count, maxm);
            }
        }
    }

    for (int i = 0; i < n; i++)
        delete[] vis[i];
    delete[] vis;

    return maxm;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int **cake = new int *[n];
    for (int i = 0; i < n; i++)
    {
        cake[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> cake[i][j];
    }
     
    cout << pieces(cake, n);

    for (int i = 0; i < n; i++)
        delete[] cake[i];
    delete[] cake;

    return 0;
}