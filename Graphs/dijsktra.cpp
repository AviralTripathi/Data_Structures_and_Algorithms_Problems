Question:  Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two 
integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . 
  You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers 
  denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9


  Code:

  class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // declaring a distance vector
        vector<int> dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[S]=0;
        pq.push({dis[S],S});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis[node]!=INT_MAX)
            {
                for(auto adjNode:adj[node])
                {
                    int v=adjNode[0];
                    int wt=adjNode[1];
                    // condition to update the distance of a node from the source vertex
                    // dis[Vj] > dis[Vi]+wt(i,j)
                    if(dist+wt<dis[v])
                    {
                        dis[v]=dist+wt;
                        pq.push({dis[v],v});
                    }
                }
            }
        }
        return dis;
    }
};


Time Complexity: O((V+E)logV)

Space Complexity: O(V+E)

