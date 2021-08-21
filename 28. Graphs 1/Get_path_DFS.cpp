/* 
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
        -- null
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> dfs(int**edges, int v, bool *vis, int v1, int v2)
{
    vector<int> path;
    if(v1 == v2)
    {
        path.push_back(v1);
        return path;
    }

    vis[v1] = true;

    for (int i = 0; i < v; i++)
    {
        if (i == v1)
            continue;

        if(edges[i][v1] == 1 and !vis[i])
        {
            path = dfs(edges, v, vis, i, v2);
            if (!path.empty())
            {
                path.push_back(v1);
                return path;
            }            
        }        
    }
    return path;
}

int main(int argc, char const *argv[])
{
    int v, e, v1, v2, f, s;
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
            edges[i][j] = 0;
    }    

    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cin >> v1 >> v2;

    bool *vis = new bool[v];
    vector<int> path;
    path = dfs(edges, v, vis, v1, v2);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";

    delete[] vis;
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;

    return 0;
}