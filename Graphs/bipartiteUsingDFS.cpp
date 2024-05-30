class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        // Set the color for the current node
        color[node] = col;
        
        for (int adjNode : graph[node]) {
            // If the adjacent node is not colored, color it with the opposite color
            if (color[adjNode] == -1) {
                if (!dfs(adjNode, 1 - col, graph, color)) {
                    return false;
                }
            } else if (color[adjNode] == col) {
                // If the adjacent node has the same color, the graph is not bipartite
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all nodes as uncolored

        // Check each component of the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // Start a DFS from this node and color it with color 0
                if (!dfs(i, 0, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};


This is the time and space complexity in total after considering the different calculations

Time Complexity: O(V+E)
  Space Complexity: O(V+E)
