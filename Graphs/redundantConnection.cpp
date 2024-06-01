Problem Statement: In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

  Explanation:

Intuition
Using Disjoint Set to find the Ultimate Parent of the edges. If the parent of both are equal, means its an redundant connection. We store such edges and in the end return ans.back()


  Code:

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            // intially marking each node as the parent of itself
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        // if node itself the parent then  simply return the node
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    // in order to find for the redundant connection; for the two nodes if there
    // ultimate parents are equal, then there exists a redundant connection
    bool findParEqual(int u, int v) { return findUpar(u) == findUpar(v); }
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u), ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<vector<int>> ans;
        for (auto it : edges) {
            if (ds.findParEqual(it[0], it[1]))
                // push the edge (two nodes) inside the ans vector
                ans.push_back(it);
            ds.unionBySize(it[0], it[1]);
        }
        return ans.back();
    }
};

Time Complexity: O(ElogV)

Space Complexity: O(n)
