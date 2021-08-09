/* Given integers M, N and K, the task is to place K knights on an M*N chessboard such that they don’t attack each other.
The knights are expected to be placed on different squares on the board. A knight can move two squares vertically and one square 
horizontally or two squares horizontally and one square vertically. The knights attack each other if one of them can reach the 
other in single move. There are multiple ways of placing K knights on an M*N board or sometimes, no way of placing them. 
We are expected to list out all the possible solutions.

Examples:

    Input: M = 3, N = 3, K = 5
    Output:
    K A K
    A K A
    K A K

    A K A
    K K K
    A K A

    Total number of solutions : 2


    Input: M = 5, N = 5, K = 13
    Output:
    K A K A K
    A K A K A
    K A K A K
    A K A K A
    K A K A K

    Total number of solutions : 1
*/
#include <iostream>
using namespace std;

int config; // number of possible knights combos possible

void print(int **visited, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 1)
                cout << "K ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **vis, int n, int i, int j)
{
    // 4 conditions checked because knights placed above can only cause issues, since there's nothing present below
    if (i - 2 >= 0 and j - 1 >= 0 and vis[i - 2][j - 1] == 1)
        return false;

    if (i - 2 >= 0 and j + 1 < n and vis[i - 2][j + 1] == 1)
        return false;

    if (i - 1 >= 0 and j - 2 >= 0 and vis[i - 1][j - 2] == 1)
        return false;

    if (i - 1 >= 0 and j + 2 < n and vis[i - 1][j + 2] == 1)
        return false;

    return true;
}

void nk_helper(int **visited, int m, int n, int row, int col, int placed, int k)
{
    if (placed == k)
    {
        print(visited, m, n);
        config++;
        return;
    }

    for (int i = row; i < m; i++)
    {
        for (int j = (i == row) ? col : 0; j < n; j++)
        {
            if (isSafe(visited, n, i, j))
            {
                visited[i][j] = 1;
                nk_helper(visited, m, n, i, j + 1, placed + 1, k);
                visited[i][j] = 0;
            }
        }
    }
}

void knights(int m, int n, int k)
{
    int **visited = new int *[m];
    for (int i = 0; i < m; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    nk_helper(visited, m, n, 0, 0, 0, k);
    delete[] visited;
}

int main(int argc, char const *argv[])
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        config = 0;
        cin >> m >> n >> k;
        knights(m, n, k);
        cout << "Configurations = " << config << endl << endl;
    }
    return 0;
}