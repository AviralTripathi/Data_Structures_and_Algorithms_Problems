Some sort of traversal would be required for graph(using DFS here), Would clone each node and add adj Node as we do DFS. The only tricky part to question 
is not to create a new Node If it is already created, For this purpose used map. If it's in map just connecting edges.

Approach
Do a DFS on original graph
As we are traversing, For the current node we are processing create a node and make an entry to map key=originalNode, value=newlyCreatedNode
while looking for adj Node see If it is already visited, if it is you don't need to do dfs and create node, just assign that we have calculate before
Note -> here map works as visited array as wekk
Complexity
Time complexity:
O(V+E) not cobsidering log(n) factor for map -> (Go ahead and use unordered_map)

Space complexity:
O(V+E)

  Code:

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    // this map is working here as a visited array as well
    // map to pair the original node to it's correponding cloned node
    map<Node*,Node*> m;
    Node* dfs(Node* u)
    {
        // copying the val of the u to u1 node since we are cloning the graph
        // so the start should be done with the help of start node;
        Node* u1=new Node(u->val);
        // map the new node to it's correponding node in the original one
        m[u]=u1;
        for(Node* v:u->neighbors)
        {
            if(m.find(v)==m.end())
            {
                // it means that a particular node which is it's neighbor has 
                // not been visited yet
                u1->neighbors.push_back(dfs(v));
                // call the dfs traversal for the neighbors of that u-node

            }
            else
            {
                // it means that particular neighbor node has been already visited
                // not by the parent node which has been consideration but by some 
                // other node 
                // assign this node to it's parent cloned node
                u1->neighbors.push_back(m[v]);
            }

        }
        return u1;
    }

public:
    Node* cloneGraph(Node* node) {
        return node?dfs(node):NULL;
    }
};
