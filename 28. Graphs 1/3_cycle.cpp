/* 
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1 
*/

#include <iostream>
using namespace std;

int countCycles(int **graph, int n, int m)
{
    int count = 0;

    // for picking the vertices
    for (int i = 0; i < n; i++)
    {
        // for picking the 2nd vertex adjacent to ith vertex
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                // for picking the 3rd vertex adjacent to jth vertex
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        continue;

                    if (graph[j][k] == 1 and graph[i][k] == 1)
                        count++;
                }
            }
        }
    }

    // since each vertex would give 2 3-Cycle graphs (1st in clockwise and 2nd in anticlockwise direction) and there are 3 vertices in the cycle,
    // so we get the count of 1 cycle 6 times
    return count / 6;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f - 1][s - 1] = 1;
        graph[s - 1][f - 1] = 1;
    }

    cout << countCycles(graph, n, m);

    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}