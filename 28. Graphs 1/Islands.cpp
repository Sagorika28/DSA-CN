/* 
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2 
*/

#include <iostream>
#include <vector>
using namespace std;

void print_dfs(int **edge_mat, int v, int start_vertex, bool *vis)
{
    vis[start_vertex] = true;

    // traverse each vertex and go depth wise
    for (int i = 0; i < v; i++)
    {
        if (i == start_vertex)
            continue;

        // if edge with the start_vertex exists, go in
        if (edge_mat[i][start_vertex] == 1)
        {
            if (!vis[i])
                print_dfs(edge_mat, v, i, vis);
        }
    }
}

int DFS(int **edge_mat, int v)
{
    // visited edges array
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
        vis[i] = false;

    int count = 0;

    // traverse the visited array & for for each unmarked vertex, call print_dfs() again
    for (int i = 0; i < v; i++)
    {
        // if any vertex is not visited, it means it's part of another component, so call dfs on it
        if (!vis[i])
        {
            count++;
            print_dfs(edge_mat, v, i, vis);
        }
    }
    delete[] vis;
    return count;
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

    // call dfs
    int result = DFS(edge_mat, v);
    cout << result;

    for (int i = 0; i < v; i++)
        delete[] edge_mat[i];
    delete[] edge_mat;
    return 0;
}