/* 
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true 
*/

#include <iostream>
using namespace std;

bool ans = false;

void dfs(char board[][1000], bool **vis, int n, int m, int i, int j, char c, int k, int pr, int pc) // pr and pc are previoud row and col
{
    // out of bounds
    if (i < 0 or j < 0 or i >= n or j >= m)
        return;

    // not the same color
    if (board[i][j] != c)
        return;

    // valid cycle found as we reach an already visited cell
    if (vis[i][j] == true and k >= 4)
    {
        ans = true;
        return;
    }

    // temporarily change the color to '.' so that recursive calls don't come back to this color as vis[i][j] = true but there's no check to stop it
    vis[i][j] = true;
    k++;

    // recursive call for finding more same coloured cells
    if (i - 1 != pr or j != pc)
        dfs(board, vis, n, m, i - 1, j, c, k, i, j);

    if (i != pr or j - 1 != pc)
        dfs(board, vis, n, m, i, j - 1, c, k, i, j);

    if (i != pr or j + 1 != pc)
        dfs(board, vis, n, m, i, j + 1, c, k, i, j);

    if (i + 1 != pr or j != pc)
        dfs(board, vis, n, m, i + 1, j, c, k, i, j);

    vis[i][j] = false;
}

bool cycle(char board[][1000], int n, int m)
{
    bool **vis = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = new bool[m];
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = board[i][j];
            if (!vis[i][j])
                dfs(board, vis, n, m, i, j, c, 0, -1, -1);
            if (ans)
                return true;
        }
    }

    for (int i = 0; i < n; i++)
        delete[] vis[i];
    delete[] vis;

    return false;
}

int main(int argc, char const *argv[])
{
    int n, m;
    char board[1000][1000];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    cout << (cycle(board, n, m) ? "true" : "false");
    return 0;
}