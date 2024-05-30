Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

Example:

Input: Graph :

example
Example

Output: 5 4 2 3 1 0
Explanation: The first vertex in topological sorting is always a vertex with an in-degree of 0 (a vertex with no incoming edges).  
A topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph.
Another topological sorting of the following graph is “4 5 2 3 1 0”.


  Algorithm for Topological Sorting using DFS:
Here’s a step-by-step algorithm for topological sorting using Depth First Search (DFS):

Create a graph with n vertices and m-directed edges.
Initialize a stack and a visited array of size n.
For each unvisited vertex in the graph, do the following:
Call the DFS function with the vertex as the parameter.
In the DFS function, mark the vertex as visited and recursively call the DFS function for all unvisited neighbors of the vertex.
Once all the neighbors have been visited, push the vertex onto the stack.
After all, vertices have been visited, pop elements from the stack and append them to the output list until the stack is empty.
The resulting list is the topologically sorted order of the graph.


Code:

#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, vector<vector<int> >& adj,
                         vector<bool>& visited,
                         stack<int>& Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
void topologicalSort(vector<vector<int> >& adj, int V)
{
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Print contents of stack
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{

    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}


Time Complexity: O(V+E)
Space Complexity: Auxillary Space : O(V)
