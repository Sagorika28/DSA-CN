#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nq_helper(int **visited, int n, int row, vector<vector<string>> &result, vector<string> temp, bool *cols, bool *ldiag, bool *rdiag)
    {
        if (row == n) // all the n queens have been placed successfully
        {
            result.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) // check for each col in the given row
        {
            if (cols[j] == false and ldiag[row + j] == false and rdiag[row - j + n - 1] == false)
            {
                visited[row][j] = 1;
                temp[row][j] = 'Q';
                cols[j] = true;
                ldiag[row + j] = true;         // row+j gives same value for all the cells in the left diagonal
                rdiag[row - j + n - 1] = true; // row-j+n-1 gives same value for all the cells in the right diagonal
                nq_helper(visited, n, row + 1, result, temp, cols, ldiag, rdiag);

                // backtrack
                visited[row][j] = 0;
                temp[row][j] = '.';
                cols[j] = false;
                ldiag[row + j] = false;
                rdiag[row - j + n - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        int **visited = new int *[n];
        vector<vector<string>> result;

        for (int i = 0; i < n; i++)
        {
            visited[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        string t;
        for (int i = 0; i < n; i++)
            t += '.';
        vector<string> temp(n);
        for (int i = 0; i < n; i++)
            temp[i] = t;

        bool *cols = new bool[n];          // array for used cols
        bool *ldiag = new bool[2 * n - 1]; // no. of diagonals = 2*n-1
        bool *rdiag = new bool[2 * n - 1];

        for (int i = 0; i < n; i++)
        {
            cols[i] = false;
        }

        for (int i = 0; i < 2 * n - 1; i++)
        {
            ldiag[i] = false;
            rdiag[i] = false;
        }

        nq_helper(visited, n, 0, result, temp, cols, ldiag, rdiag);
        delete[] visited;
        delete[] cols;
        delete[] ldiag;
        delete[] rdiag;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<string>> res = s.solveNQueens(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << res[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
