The use of disjoint sets (also known as union-find data structures) in Kruskal's algorithm is based on efficiently managing and merging sets of
  vertices to ensure that the Minimum Spanning Tree (MST) remains acyclic while including the minimum weight edges. Here's the theoretical intuition
  behind using disjoint sets and union operations:

Theoretical Intuition:
Graph Partitioning:

In Kruskal's algorithm, the graph is progressively divided into several disjoint sets of vertices. Initially, each vertex is in its own set. 
  The goal is to merge these sets until all vertices are connected in a single set, forming the MST.
Cycle Detection:

To prevent cycles in the MST, it's crucial to determine whether two vertices belong to the same set (connected by some path) before adding an edge between them. 
  If they are already in the same set, adding the edge would create a cycle. Disjoint sets allow for efficient checking and merging of these sets.
Union-Find Operations:

Find Operation: This operation determines which set a particular element belongs to. It is used to check if two vertices are in the same set.
Union Operation: This operation merges two sets into a single set. It is used to combine the sets of two vertices after adding an edge between them,
ensuring they are treated as a connected component in subsequent operations.
Steps in Kruskal's Algorithm with Disjoint Sets:
Initialization:

Each vertex is initialized in its own set. This is done by setting the parent of each vertex to itself.
Edge Processing:

All edges are sorted in non-decreasing order of their weights.
Edge Selection:

Iterate through the sorted edges. For each edge, check if the two vertices connected by the edge belong to different sets using the find operation.
If they belong to different sets, include the edge in the MST and merge the sets using the union operation.
Benefits of Using Disjoint Sets:
Efficient Cycle Detection:

The find operation quickly determines whether adding an edge would create a cycle by checking if the two vertices are already in the same set.
Efficient Set Merging:

The union operation efficiently merges two sets, ensuring that the sets are combined without creating cycles.
Path Compression and Union by Size/Rank:

These optimizations ensure that the find and union operations are nearly constant time, making the overall algorithm very efficient.
Detailed Explanation of Union-Find Data Structure:
Path Compression:

During the find operation, path compression flattens the structure of the tree by making nodes point directly to the root. This reduces the time complexity 
of future operations.
Union by Size/Rank:

When merging two sets, union by size or rank attaches the smaller tree under the larger tree. This keeps the tree shallow, ensuring that the depth of the 
tree remains small, leading to efficient operations.

Summary:
The intuition behind using disjoint sets in Kruskal's algorithm is to efficiently manage the merging of sets of vertices to form the MST while avoiding cycles. 
  The union-find data structure allows for efficient cycle detection and merging operations, making the algorithm both correct and efficient. 
The optimizations of path compression and union by size/rank ensure that these operations are performed in nearly constant time, contributing to the overall 
efficiency of the algorithm.


explain the use of size vector in the above program along with the two functions findUpar and union_by_size give their proper explanation as well'
ChatGPT
Explanation of the size Vector, findUpar, and union_by_size Functions
The size vector, along with the findUpar and union_by_size functions, are integral parts of the Union-Find (Disjoint Set) data structure. They help in efficiently managing and merging sets of vertices, which is crucial for Kruskal's algorithm to build the Minimum Spanning Tree (MST) without forming cycles.

size Vector
The size vector is used to keep track of the size of each set. The size of a set is defined as the number of elements (vertices) in the set. The size vector helps in optimizing the union operation by always attaching the smaller set to the larger set, thus keeping the resulting tree shallow. This optimization ensures that the depth of the trees remains small, which in turn keeps the time complexity of the findUpar and union_by_size operations nearly constant.

findUpar Function
The findUpar (find ultimate parent) function is used to find the root (ultimate parent) of a node. It also implements path compression, which is a
                technique to make future findUpar operations faster by flattening the structure of the tree.

                
  int findUpar(int node) {
    // Base case: if the node is its own parent, return the node
    if (node == parent[node]) return node;

    // Recursive case: find the ultimate parent of the node
    // Path compression: make the parent of the node point directly to the root
    return parent[node] = findUpar(parent[node]);
}
Base Case: If the node is its own parent, it is the root of the set, and we return it.
Recursive Case: If the node is not its own parent, we recursively call findUpar on its parent. The result is then used to directly update the parent of the node, thus flattening the tree. This path compression ensures that all nodes directly point to the root, reducing the depth of the tree and making subsequent findUpar operations faster.
union_by_size Function
The union_by_size function merges two sets by linking the root of the smaller set to the root of the larger set. This keeps the trees shallow, optimizing the Union-Find operations.

  void union_by_size(int u, int v) {
    // Find the ultimate parents (roots) of the nodes u and v
    int ulp_u = findUpar(u);
    int ulp_v = findUpar(v);

    // If they are already in the same set, do nothing
    if (ulp_u == ulp_v) return;

    // Union by size: attach the smaller tree under the larger tree
    if (size[ulp_u] > size[ulp_v]) {
        // Attach the tree of v to the tree of u
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    } else {
        // Attach the tree of u to the tree of v
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
}
Finding Roots: The function first finds the ultimate parents (roots) of the nodes u and v using the findUpar function.
Check for Same Set: If the roots of u and v are the same, it means they are already in the same set, and no union operation is needed.
Union by Size:
If the size of the set containing u is greater than the size of the set containing v, we attach the root of v's set (ulp_v) to the root of u's set (ulp_u). 
  The size of u's set is updated to reflect the new total size.
Otherwise, we attach the root of u's set (ulp_u) to the root of v's set (ulp_v). The size of v's set is updated accordingly.
Intuition and Benefits
Path Compression: The findUpar function with path compression ensures that the tree height remains small, leading to nearly constant time complexity 
for the find operation.
Union by Size: The union_by_size function ensures that the smaller tree is always attached to the larger tree. This prevents the tree from becoming too deep, 
optimizing the find and union operations.
Efficiency: Both path compression and union by size are critical optimizations that make the Union-Find data structure very efficient, with nearly constant 
time complexity for both find and union operations. This efficiency is crucial for algorithms like Kruskal's, where multiple union and find operations are 
performed.
By combining path compression and union by size, the Union-Find data structure ensures that operations are performed efficiently, making it well-suited 
for applications in network connectivity, image processing, and MST algorithms like Kruskal's.

what is the use of the resize in the above program and how we have made the list of the list for the edges?
Use of resize in the Disjoint Set Class
The resize function is used to initialize the parent and size vectors to the appropriate size, ensuring they can accommodate all the vertices in the graph.

Summary
The resize function is used to initialize and allocate space for the parent and size vectors, ensuring they can accommodate all vertices in the graph. 
  The adjacency list representation of the graph is converted into a list of edges by iterating over the adjacency list and extracting each edge, 
  represented as a pair consisting of the weight and the vertices it connects. This edge list is then used in Kruskal's algorithm to construct the
  Minimum Spanning Tree.


Code:


class disjointSet
{
    // The size vector is used to keep track of the size of each set. 
    // The size of a set is defined as the number of elements (vertices) in the set. 
    vector<int> parent,size;
    public:
    disjointSet(int n)
    {
//         parent.resize(n + 1): This line sets the size of the parent vector to n + 1. 
//         This ensures that there is enough space to store the parent for each vertex from 0 to n (inclusive).
// size.resize(n + 1, 1): This line sets the size of the size vector to n + 1 and 
// initializes each element to 1. This means that initially, 
// each vertex is its own set and has a size of 1.
        parent.resize(n+1);
        size.resize(n+1,1);
        // now for each node map it's parent to the node itself
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            
        }
    }
    int findUpar(int node)
    {
        // through this we will be trying to find the parent of a particular node: 'node'
        if(node==parent[node])
        // returned the node taken as input parameter in this case 
        return node;
        // find the parent node in case the node is not the parent node of itself
        // If the node is not its own parent, we recursively call findUpar on its parent. 
        // The result is then used to directly update the parent of the node, thus flattening the tree.
        // This path compression ensures that all nodes directly point to the root, reducing the depth of 
        // the tree and making 
        // subsequent findUpar operations faster.
        return parent[node]=findUpar(parent[node]);
    }
    // this function is used to check whether the two nodes are from the same set or not
    // and in that case there is no need to insert an edge between the two nodes otherwise we will be 
    // inserting the edge between the two nodes u and v
    void union_by_size(int u,int v)
    {
        // this is to find the ultimate parent (root) of each node
        // find the parent of the two nodes
        // The union_by_size function merges two sets by linking the root of the smaller set to 
        // the root of the larger set. 
        // This keeps the trees shallow, optimizing the Union-Find operations
        int f_node=findUpar(u);
        int s_node=findUpar(v);
        // this means that they belong to the same set so there is no need of edge creation between them
        if(f_node==s_node)return;
        if(size[f_node]>size[s_node])
        {
            // root of s_node is attached to the f_node the one which has got more elements in it's set
        parent[f_node]=s_node;
        size[f_node]+=size[s_node];
        }
        else
        {
            // root of f_node is attached to the s_node the one which has got more element's in it's set
            parent[s_node]=f_node;
            size[s_node]+=size[f_node];
        }
    }
    // here we are using these brackets [] since inside a class we are trying to variables which hold the 
    // values returned by the functions which are the static members of that class
    
    
//     Finding Roots: The function first finds the ultimate parents (roots) of the nodes u and v using 
//     the findUpar function.
// Check for Same Set: If the roots of u and v are the same, it means they are already in the same set, 
// and no union operation is needed.
// Union by Size:
// If the size of the set containing u is greater than the size of the set containing v, 
// we attach the root of v's set (ulp_v) to the root of u's set (ulp_u). The size of u's set
// is updated to reflect the new total size.
// Otherwise, we attach the root of u's set (ulp_u) to the root of v's set (ulp_v). 
// The size of v's set is updated accordingly.

};





class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        int sum=0;
        disjointSet ds(V);
            // extracting all the edges
            for(int i=0;i<V;i++)
            {
                for(auto it:adj[i])
                {
                    // here for every node ;it's adjacent neighbours it[1]:weight i& it[0] are the nodes
                    // having the edge
                    edges.push_back({it[1],{i,it[0]}});
                }
            }
            // sort the edges by weight
            sort(edges.begin(),edges.end());
        // Kruskal's algorithm
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUpar(u) != ds.findUpar(v)) {
                sum += wt;
                // calling the union by size function from the disjointSet class
                ds.union_by_size(u, v);
            }
        }
        return sum;


    }
};


Time Complexity: O(ElogE)
Space Complexity: O(V+E)
