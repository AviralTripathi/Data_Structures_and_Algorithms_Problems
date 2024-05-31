Meaning of strongly connected components:

A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component. It can only be used in a directed graph.

Brute Force Approach for Finding Strongly Connected Components:
The simple method will be for each vertex i (which is not a part of any strongly component) find the vertices which will be the part of strongly connected component containing vertex i. Two vertex i and j will be in the same strongly connected component if they there is a directed path from vertex i to vertex j and vice-versa.

Code:

#include <bits/stdc++.h>
using namespace std;

class GFG {
public:
    // dfs Function to reach destination
    bool dfs(int curr, int des, vector<vector<int> >& adj,
             vector<int>& vis)
    {

        // If curr node is destination return true
        if (curr == des) {
            return true;
        }
        vis[curr] = 1;
        for (auto x : adj[curr]) {
            if (!vis[x]) {
                if (dfs(x, des, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    // To tell whether there is path from source to
    // destination
    bool isPath(int src, int des, vector<vector<int> >& adj)
    {
        vector<int> vis(adj.size() + 1, 0);
        return dfs(src, des, adj, vis);
    }

    // Function to return all the strongly connected
    // component of a graph.
    vector<vector<int> > findSCC(int n,
                                 vector<vector<int> >& a)
    {
        // Stores all the strongly connected components.
        vector<vector<int> > ans;

        // Stores whether a vertex is a part of any Strongly
        // Connected Component
        vector<int> is_scc(n + 1, 0);

        vector<vector<int> > adj(n + 1);

        for (int i = 0; i < a.size(); i++) {
            adj[a[i][0]].push_back(a[i][1]);
        }

        // Traversing all the vertices
        for (int i = 1; i <= n; i++) {

            if (!is_scc[i]) {

                // If a vertex i is not a part of any SCC
                // insert it into a new SCC list and check
                // for other vertices whether they can be
                // thr part of thidl ist.
                vector<int> scc;
                scc.push_back(i);

                for (int j = i + 1; j <= n; j++) {

                    // If there is a path from vertex i to
                    // vertex j and vice versa put vertex j
                    // into the current SCC list.
                    if (!is_scc[j] && isPath(i, j, adj)
                        && isPath(j, i, adj)) {
                        is_scc[j] = 1;
                        scc.push_back(j);
                    }
                }

                // Insert the SCC containing vertex i into
                // the final list.
                ans.push_back(scc);
            }
        }
        return ans;
    }
};

// Driver Code Starts

int main()
{

    GFG obj;
    int V = 5;
    vector<vector<int> > edges{
        { 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }
    };
    vector<vector<int> > ans = obj.findSCC(V, edges);
    cout << "Strongly Connected Components are:\n";
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}


Time Complexity: O(n*(n+m))
Space Complexity: O(n)


Explaination:

To find the strongly connected components of a given directed graph, we are going to use Kosaraju’s Algorithm.

Before understanding the algorithm, we are going to discuss the thought process behind it. If we start DFS from node 0 for the following graph, we will end up visiting all the nodes. So, it is impossible to differentiate between different SCCs.


Now, we need to think in a different way. We can convert the above graph into the following illustration:


By definition, within each SCC, every node is reachable. So, if we start DFS from a node of SCC1 we can visit all the nodes in SCC1 and via edge e1 we can reach SCC2. Similarly, we can travel from SCC2 to SCC3 via e2 and SCC3 to SCC4 via e3. Thus all the nodes of the graph become reachable.

But if we reverse the edges e1, e2, and e3, the graph will look like the following:


Now in this graph, if we start DFS from node 0 it will visit only the nodes of SCC1. Similarly, if we start from node 3 it will visit only the nodes of SCC2. Thus, by reversing the SCC-connecting edges, the adjacent SCCs become unreachable. Now, the DFS will work in such a way, that in one DFS call we can only visit the nodes of a particular SCC. So, the number of DFS calls will represent the number of SCCs.

Until now, we have successfully found out the process of getting the number of SCCs. But here, comes a new problem i.e. if we do not know the SCCs, how the edges will be reversed? To solve this problem, we will simply try to reverse all the edges of the graph like the following:


If we carefully observe, the nodes within an SCC are reachable from each one to everyone even if we reverse the edges of the SCC. So, the SCCs will have no effect on reversing the edges. Thus we can fulfill our intention of reversing the SCC-connecting edge without affecting the SCCs.

Now, the question might be like, if node 0 is located in SCC4 and we start DFS from node 0, again we will visit all the SCCs at once even after reversing the edges. This is where the starting time and the finishing time concept will come in.

Now, we have a clear intuition about reversing edges before we move on to the starting and the finishing time concept in the algorithm part.

Algorithm: 

The algorithm steps are as follows:

Sort all the nodes according to their finishing time:
To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.
Reverse all the edges of the entire graph:
Now, we will create another adjacency list and store the information of the graph in a reversed manner.
Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.
Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.
Note: 

The first step is to know, from which node we should start the DFS call.
The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.
The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.
Note: The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.




Code:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> &vis, vector<int> adjT[], vector<int> &component) {
        vis[node] = 1;
        component.push_back(node); // store node in the current SCC component
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT, component);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[], vector<vector<int>> &scc) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Perform DFS and fill the stack in order of finish times
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Create the transpose of the graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transpose graph in the order defined by the stack
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> component;
                dfs3(node, vis, adjT, component);
                scc.push_back(component); // store the current SCC
            }
        }

        return scc.size(); // return the number of SCCs
    }
};

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    vector<vector<int>> scc;
    int num_scc = obj.kosaraju(n, adj, scc);

    cout << "Number of strongly connected components: " << num_scc << endl;
    cout << "Strongly connected components: " << endl;
    for (int i = 0; i < scc.size(); i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            cout << scc[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


Time Complexity: O(V+E)

  // note solving with the help of brute force approach will result into the time complexity of O(n*(n+m))

Space Complexity: O(V+E)
