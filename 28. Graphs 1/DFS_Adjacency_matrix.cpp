#include <iostream>
using namespace std;

void print_dfs(int **edge_mat, int v, int start_vertex, bool *vis)
{
    cout << start_vertex << endl;
    vis[start_vertex] = true;

    // traverse each vertex and go depth wise
    for (int i = 0; i < v; i++)
    {
        if (i == start_vertex)
            continue;
        
        // if edge with the start_vertex exists, go in
        if (edge_mat[i][start_vertex] == 1)
        {
            if(!vis[i])
                print_dfs(edge_mat, v, i, vis);
        }
    }    
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

    // visited edges array
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
        vis[i] = false;
    
    // call dfs
    print_dfs(edge_mat, v, 0, vis);

    delete[] vis;

    for (int i = 0; i < v; i++)
        delete[] edge_mat[i];
    delete[] edge_mat;

    return 0;
}