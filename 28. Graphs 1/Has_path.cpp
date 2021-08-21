/* 
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false 
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool find_dfs(int **edge_mat, int v, int start_vertex, bool *vis, int b)
{
    if (start_vertex == b)
        return true;

    vis[start_vertex] = true;

    // traverse each vertex and go depth wise
    for (int i = 0; i < v; i++)
    {
        if (i == start_vertex)
            continue;

        // if edge with the start_vertex exists, go in
        if (edge_mat[i][start_vertex] == 1 and !vis[i])
        {
            if (find_dfs(edge_mat, v, i, vis, b))
                return true;
        }
    }
    return false;
}

bool find_bfs(int **edge_mat, int v, int sv, bool *vis, int b)
{
    queue<int> pendingVertices;

    // push the sv into the queue, mark it visited
    pendingVertices.push(sv);
    vis[sv] = true;

    while (!pendingVertices.empty())
    {
        // extract the front() and remove it from queue
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        // check current's neighbours and push into the queue if not visited
        for (int i = 0; i < v; i++)
        {
            if (i == currentVertex)
                continue;

            if (edge_mat[i][currentVertex] == 1 and !vis[i])
            {
                if (i == b)
                    return true;
                pendingVertices.push(i);
                vis[i] = true;
            }
        }
    }
    return false;
}

// for disconnected components, we check the visited array after it has been marked to see which
// vertex is not markede yet and call DFS on that disconnected vertex again
bool DFS(int **edge_mat, int v, int a, int b)
{
    // visited edges array
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
        vis[i] = false;

    // check the adjacent vertices of a to see if there's a direct edge from a to b or not
    if (edge_mat[a][b] == 1)
    {
        delete[] vis;
        return true;
    }

    // traverse the visited array & for for each unmarked vertex, call print_dfs() again
    bool ans = find_dfs(edge_mat, v, a, vis, b);
    delete[] vis;
    return ans;
}

bool BFS(int **edge_mat, int v, int a, int b)
{
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
        vis[i] = false;

    // check the adjacent vertices of a to see if there's a direct edge from a to b or not
    if (edge_mat[a][b] == 1)
    {
        delete[] vis;
        return true;
    }

    // traverse the visited array & for for each unmarked vertex, call print_dfs() again
    bool ans = find_bfs(edge_mat, v, a, vis, b);
    delete[] vis;
    return ans;
}

int main(int argc, char const *argv[])
{
    int v, e;
    cin >> v >> e;

    // adjacency matrix
    int **edge_mat = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edge_mat[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edge_mat[i][j] = 0;
        }
    }

    // fill the matrix by taking the first and second vertices that form an edge
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edge_mat[f][s] = 1;
        edge_mat[s][f] = 1;
    }

    // take in start and end vertex
    int a, b;
    cin >> a >> b;

    // call dfs
    cout << "DFS: ";
    cout << (DFS(edge_mat, v, a, b) ? "true" : "false");

    // call bfs
    cout << "\nBFS: ";
    cout << (BFS(edge_mat, v, a, b) ? "true" : "false");

    for (int i = 0; i < v; i++)
        delete[] edge_mat[i];
    delete[] edge_mat;

    return 0;
}