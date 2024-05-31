The algorithm implemented in the provided code is Prim's algorithm. Here's a brief explanation of why this is Prim's algorithm and the time complexity analysis:

Identification of Prim's Algorithm:
Initialization with a Priority Queue:

The code uses a priority queue (pq) to select the edge with the minimum weight.
This is characteristic of Prim's algorithm, where a priority queue is used to find the next edge with the smallest weight that expands the tree.
Starting from an Arbitrary Node:

The code starts from node 0 (pq.push({0,0});), indicating the start of the MST from an arbitrary node, typical in Prim's algorithm.
Edge Selection and Expansion:

It continuously adds the smallest edge that connects a vertex not yet in the MST (if(visited[node]==1) continue; and visited[node]=1;).
Edges are added to the priority queue only if they connect to an unvisited node (if(visited[it[0]]==0){ pq.push({it[1],it[0]}); }).




Code:

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        vis[0]=0;
        // initially the sum of the minimum cost of the bst is 0
        int sum=0;
        // push the weight alonwith the node inside the priority
        pq.push({0,0});
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int value=temp.first;
            int node=temp.second;
            
            // if the node has been already then skip it
            if(vis[node]==1)continue;
            sum+=value;
            // mark the node as visited 
            vis[node]=1;
            for(auto adjNode: adj[node])
            {
                if(!vis[adjNode[0]])
                {
                    // push the value alongwith the node inside the priority queue
                    pq.push({adjNode[1],adjNode[0]});
                }
            }
        }
        return sum;
    }
};


Time Complexity: O(ElogV)
Space Complexity: O(V+E)
