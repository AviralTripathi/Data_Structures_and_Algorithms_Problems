Problem Statement:  There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
(I)
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
(ii)
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

  (iii)
Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

  Code:

// Basic intution of this problem is to notice that inorder to reach the capital
// city all the forward will be changed or reoriented to incoming edges towards
// city0 so min oreintation means that we will have to count the number of
// forward edges and return the same. the reference for the same can be drawn
// from given test case as well.

class Solution {
private:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis, int& c) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            int dir = it.second;
            if (!vis[v]) {
                // counting the number of forward edges
                // 1---forward edge
                // 2--- backward edge
                if (dir == 1)
                    c++;
                dfs(v, adj, vis, c);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            // 1-forward edge
            // 2-backward edge
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 2});
        }
        // this will count the total number of forward edges that needs to be
        // reoreinted in order to make connection for every city to reach city0
        int c = 0;
        vector<int> vis(n, 0);
        // since it is a 0-index based graph so we are starting our dfs
        // traversal from the node 0 only.
        dfs(0, adj, vis, c);
        // finally return the total number of forward edges.
        return c;
    }
};

Time Complexity: O(V+E)

Space Complexity: O(V+E)
