Code:

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        // iterating once more to check for the negative cycle
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};

Time Complexity: O(VE)

Space Complexity: O(V+E)

