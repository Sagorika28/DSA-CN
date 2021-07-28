/* 
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move 
are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be 
crossed while value 1 at a cell in the matrix represents that it can be traveled through. 
*/
#include <iostream>
using namespace std;
int count = 0;

// to find whether path exists or not
bool hasPathHelper(int **arr, int n, int **visited, int x, int y)
{
    // if last cell (destination) has been reached, path has been found so return true
    if (x == n - 1 && y == n - 1)
        return true;

    // if cell is out of limits or it's blocked (0) or it has already been visited in a previous path of other adjacent cells, return false as there's no further path
    if (x < 0 || y < 0 || x >= n || y >= n || (arr[x][y] == 0) || (visited[x][y] == 1))
        return false;

    // mark cell as visited before searching further
    visited[x][y] = 1;

    // call recursive path search in all 4 directions and check for existing path
    if (hasPathHelper(arr, n, visited, x - 1, y)) // left
        return true;
    if (hasPathHelper(arr, n, visited, x, y - 1)) // up
        return true;
    if (hasPathHelper(arr, n, visited, x + 1, y)) // right
        return true;
    if (hasPathHelper(arr, n, visited, x, y + 1)) // down
        return true;

    // mark cell as not visited as no further path from this cell was found
    visited[x][y] = 0;
    return false;
}

bool hasMazePath(int **arr, int n)
{
    // create a 2D visited array
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0; // mark all of the cells as unvisited
        }
    }
    return hasPathHelper(arr, n, visited, 0, 0); // assuming (0, 0) to be the starting point
}

// to print all possible paths
void printPathHelper(int **arr, int n, int **visited, int x, int y)
{
    // if last cell (destination) has been reached, print the path
    if (x == n - 1 && y == n - 1)
    {
        count++;
        visited[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // if cell is out of limits or it's blocked (0) or it has already been visited in a previous path of other adjacent cells, just return as there's no further path
    if (x < 0 || y < 0 || x >= n || y >= n || (arr[x][y] == 0) || (visited[x][y] == 1))
        return;

    // mark cell as visited before searching further
    visited[x][y] = 1;

    // call recursive path search in all 4 directions and find the further paths
    printPathHelper(arr, n, visited, x - 1, y); // left
    printPathHelper(arr, n, visited, x, y - 1); // up
    printPathHelper(arr, n, visited, x + 1, y); // right
    printPathHelper(arr, n, visited, x, y + 1); // down

    // mark cell as not visited as no further path from this cell was found
    visited[x][y] = 0;
}

void printMazePaths(int **arr, int n)
{
    // create a 2D visited array
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0; // mark all of the cells as unvisited
        }
    }
    return printPathHelper(arr, n, visited, 0, 0); // assuming (0, 0) to be the starting point
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << (hasMazePath(arr, n) ? "Path exists" : "Path doesn't exist") << endl;
    printMazePaths(arr, n);
    cout << "Number of paths: " << count;
    delete[] arr;
    return 0;
}