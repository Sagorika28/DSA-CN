/* 
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5 
*/
// T=O(n*n)
#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distance, bool *visVertex, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visVertex[i] and (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *vis = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        vis[i] = false;
    }

    distance[0] = 0;

    // (n-1)*2n
    for (int i = 0; i < n - 1; i++) // n-1
    {
        int minVertex = findMinVertex(distance, vis, n); // n
        vis[minVertex] = true;
        for (int j = 0; j < n; j++) // n
        {
            if (edges[minVertex][j] != 0 and !vis[j])
            {
                int dist = distance[minVertex] + edges[minVertex][j];
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    delete[] vis;
    delete[] distance;
}

int main(int argc, char const *argv[])
{
    int n, e, dist, f, s;
    cin >> n >> e;
    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        cin >> f >> s >> dist;
        edges[f][s] = dist;
        edges[s][f] = dist;
    }

    cout << endl;
    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;

    return 0;
}