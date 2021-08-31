/* 
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
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
1 2 1
0 1 3
0 3 5 
*/
// T=O(E log V)

#include <iostream>
#include <algorithm>
using namespace std;

// make an Edge class
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

// customized sorting algo
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight; // for ascending
}

// find the first parent
int findParent(int v, int *parent)
{
    if (v == parent[v])
        return v;

    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int e)
{
    // sort the input edge array according to weights in ascending order
    sort(input, input + e, compare);

    // make an output array of MST edges
    Edge *output = new Edge[n - 1];

    // make a parent array to store the 1st parent for each vertex
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // pick edges 1 by 1 and check if it's safe to add in the MST or not
    int count = 0, i = 0;
    while (count < n - 1)
    {
        Edge currentEdge = input[i];

        // check for cycle by checking if the src and dest vertices of an edge have the same parents, if not then add edge in MST
        int srcParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (srcParent != destParent) // we can add this edge
        {
            output[count] = currentEdge;
            count++;

            // make destParent as the new parent of srcParent or vice versa
            parent[srcParent] = destParent;
        }

        i++;
    }

    // print the MST
    cout << "MST: \n";
    for (int i = 0; i < count; i++)
    {
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;

        else
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskals(input, n, e);
    delete[] input;
    return 0;
}