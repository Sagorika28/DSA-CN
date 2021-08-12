/* 
Given a N*N board with the Knight placed on the [r][c] block of an empty board. Moving according to the rules of chess knight 
must visit each square exactly once. Print the order of each the cell in which they are visited. 
Input : 
N = 8 0 0
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
*/
#include <iostream>
using namespace std;

void print(int **vis, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void knight_tour(int **vis, int n, int placed, int row, int col)
{
    if (row < 0 or row >= n or col < 0 or col >= n or vis[row][col] > 0)
        return;

    if (placed == n * n)
    {
        vis[row][col] = placed;
        print(vis, n);
        vis[row][col] = 0;
        return;
    }

    vis[row][col] = placed;
    knight_tour(vis, n, placed + 1, row - 2, col + 1);
    knight_tour(vis, n, placed + 1, row - 1, col + 2);
    knight_tour(vis, n, placed + 1, row + 1, col + 2);
    knight_tour(vis, n, placed + 1, row + 2, col + 1);
    knight_tour(vis, n, placed + 1, row + 2, col - 1);
    knight_tour(vis, n, placed + 1, row + 1, col - 2);
    knight_tour(vis, n, placed + 1, row - 1, col - 2);
    knight_tour(vis, n, placed + 1, row - 2, col - 1);
    vis[row][col] = 0;
}

void knights(int n, int r, int c)
{
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
            visited[i][j] = -1;
    }
    knight_tour(visited, n, 1, r, c);
    delete[] visited;
}

int main(int argc, char const *argv[])
{
    int n, r, c;
    cin >> n, r, c;
    knights(n, r, c);
    return 0;
}