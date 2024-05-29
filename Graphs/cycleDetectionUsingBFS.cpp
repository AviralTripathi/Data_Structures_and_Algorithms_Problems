class Solution {
    private:
    bool detectCycle(int src,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[node])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }
                // now the case for if the node has been already visited
                else if(parent !=adjNode)
                {
                    // this simply means that the node has been visited but it has not come from it's parent
                    // parent!=adjNode can be more understood from making the adjcancey list
                    // but this clearly indicates the presence of a cycle
                    return true;
                }
                
            }
        }
        // now simply return false indicating there is no cycle after complete traversal of all nodes of the
        // graph
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // so the graph is a zero based indexing graph
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i,adj,vis)==true)
                return true;
            }
        }
        return false;
    }
};


Time Complexity: O(N) + O(N+2E)
  // for the loop running for different components and n+2e because there are n nodes and in the worst case it will be travelling all it's neighbours that is 
  // equal to the summation of the degress =2E
Space Complexity: O(N)
