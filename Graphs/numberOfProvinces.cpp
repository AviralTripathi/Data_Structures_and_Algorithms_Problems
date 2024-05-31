Code:

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


// here we have created a vector of vector of the adjacency list present 
// it is same as the one that we use just for the input format we have compiled it 
// a vector of the vector having the neighbours for every node in total giving rise
// to the adjacency list.


Time Complexity: O(N)

Space Complexity: O(N)
