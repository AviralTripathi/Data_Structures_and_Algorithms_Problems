Intuition
The problem is to determine whether it is possible to finish all courses given a list of prerequisites. We can model this as a directed graph problem, where each course is a node in the graph, and the prerequisites define the edges between the courses.

The intuition behind the solution is to perform a depth-first search (DFS) traversal on the graph and check for cycles. If there's a cycle in the graph, it means there's a dependency loop, and it's impossible to finish all courses. Otherwise, if no cycle is detected, it's possible to complete all courses.

Approach
Graph Representation: The prerequisites are represented as a directed graph, where each course is a node, and the prerequisite relationships are edges between nodes.

DFS Traversal with Cycle Detection:The dfs function performs a DFS traversal from a given node. It maintains two maps: visited to keep track of nodes visited during traversal and dfsvisited to keep track of nodes visited in the current DFS traversal to detect cycles.
It explores all adjacent nodes of the current node and recursively calls DFS for unvisited nodes.
If it encounters a node that is already visited in the current DFS traversal (dfsvisited), it indicates a cycle, and the function returns true.
If no cycle is found during the DFS traversal, the function returns false.

Main Function:First, it constructs the adjacency list representation of the graph based on the prerequisites.
Then, it iterates through all the courses. For each course that hasn't been visited yet, it performs a DFS traversal starting from that course. If a cycle is detected during the DFS traversal, it returns false immediately, indicating that it's impossible to finish all courses.
If the loop completes without finding any cycle, it returns true, indicating that it's possible to finish all courses.

Complexity
Time complexity:
Constructing the adjacency list: O(E), where E is the number of edges (prerequisites). In the worst case, we iterate through all prerequisites to construct the adjacency list.
DFS Traversal: O(V + E), where V is the number of vertices (courses) and E is the number of edges (prerequisites). This is because in the worst case, we traverse through all vertices and edges in the graph.
Overall Time Complexity: O(V + E), where V is the number of vertices (courses) and E is the number of edges (prerequisites). The dominant factor is the DFS traversal.
Space complexity:
O(V+E)


Code:

class Solution {
private:
    bool dfs(int node, unordered_map<int, bool>& visited,
             unordered_map<int, bool>& dfsvisited, vector<int> adj[]) {
        // Initially mark the source node as visited
        visited[node] = true;
        dfsvisited[node] = true;

        // Traverse the neighbours of the source node
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (dfs(adjNode, visited, dfsvisited, adj) == true)
                    return true;
            } else if (dfsvisited[adjNode]) {
                // If the node is already visited in the current DFS path, a
                // cycle is present
                return true;
            }
        }

        // Unmark the node for the current DFS path
        // dfsvisited[node]=false is used to unmark the node once all its
        // descendants have been processed, which ensures that the same node can
        // be visited in different paths without incorrectly detecting a cycle.
        dfsvisited[node] = false;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        // Build the adjacency list
        for (auto x : prerequisites) {
            adj[x[1]].push_back(x[0]);
        }

        // Maps to track visited nodes and nodes visited in the current DFS path
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

        // Loop for disconnected graph
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool ans = dfs(i, visited, dfsvisited, adj);
                if (ans)
                    return false;
            }
        }
        return true;
    }
};

Time Complexity:
O(V+E)
Space Complexity: O(V+E)
