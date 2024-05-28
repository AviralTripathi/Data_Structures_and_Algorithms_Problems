class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, adj, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // to find the number of nodes in the graph
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(V, 0);
        int count = 0;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
        
        return count;
    }
};


Time Complexity:

Space Complexity:

