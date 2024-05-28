//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // initially will be creating a visited array
        // intializing the node zero with since  upon checking the graph is a zero-indexing based 
        // graph
        int vis[V]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


Space Complexity: O(3N)
since we are declaring a visited array, a bfs vector to print the bfs traversal of the given graph and the queue which at max will be holding the total number of nodes
all 3 things will be holding maximum upto the number of elements given = number of the nodes given in the graph

Time Complexity: O(N) +O(2E)
  since for the queue maximum it will iterate to all the nodes present in the graph and for inner loop for each node all its neighbours will be iterated = to the degree of the node and for all the nodes
present in the graph this will be equal to twice the edges present in the graph.
