Code:

void Graph::topologicalSort()
{
    // Create a vector to store in-degree of all vertices
    vector<int> in_degree(V, 0);

    // Traverse adjacency lists to fill in_degree of
    // vertices
    for (int v = 0; v < V; ++v) {
        for (auto const& w : adj[v])
            in_degree[w]++;
    }

    // Create a queue and enqueue all vertices with
    // in-degree 0
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    // Initialize count of visited vertices
    int count = 0;

    // Create a vector to store topological order
    vector<int> top_order;

    // One by one dequeue vertices from queue and enqueue
    // adjacent vertices if in-degree of adjacent becomes 0
    while (!q.empty()) {
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end();
             ++itr)
            // If in-degree becomes zero, add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);

        count++;
    }

    // Check if there was a cycle
    if (count != V) {
        cout << "Graph contains cycle\n";
        return;
    }

    // Print topological order
    for (int i : top_order)
        cout << i << " ";
}


Time n Space Complexity:

Time Complexity: O(V+E)
Space Complexity: O(V+E)  due to storing the elements through as=djacency list and then have created a vector of  indegree which in the worst case can have 
all the nodes directed to that particular single node.
