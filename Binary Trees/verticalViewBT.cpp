Given a binary tree, print it vertically. The following example illustrates vertical order traversal. 
 

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
              
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 

  Algorithm to approach a problem:
- firstly using the findMax function we need to maximum and minimum horizontal from the root node and recursively every node is checked being the root node
-since for a particular horizontal distance there can be more than 1 points so it can be stored in a single variable and for that in order to map the 
- values with their hd values we have used here the map with hd as key and a vector of int type will be values of the map
-next task is to perfrom the bfs that is level order traversal for which we have to declare a queue  and the format of the queue will be a pair fomrat which will
-store the node along-with the horizontal distance.
  -for recursively going to the left subtree take the hd=hd-1;
-for recursively going into the right subtree take the hd=hd+1;
-finally baesd upon the syntax of the given function we are suppose to return a vector so from map values vector ans will be having the final answer

Time Complexity: O(n) +O(k*m) where k is the number of elements in a vector and m is the number of vetors 
since in worst case there will be all the nodes of the tree that needs to be traversed 
through bfs and ans vector will also get n values from interator
Space Complexity: O(n+n)  on ignoring the constants it will be simply O(n) // because of map and queue


// here is the code for the same:

 void findMax(Node* root,int* min,int* max,int hd)
    {
        // firsly check for the root being null or not
        if(!root)
        return;
        // updating the min & max
        if(hd < *min)
        *min=hd;
        else if(hd > *max)
        *max=hd;
        
        // recursive call for the left and right subtrees
        findMax(root->left,min,max,hd-1);
        // recursive call for the right subtree
        findMax(root->right,min,max,hd+1);
        
    }
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
       //Check if the tree is empty
    if (!root) return {};

    // Map to store nodes at each vertical level
    map<int, vector<int>> m;

    // Queue for level order traversal
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    // Perform level order traversal
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Store the node in the map
            m[hd].push_back(node->data);

            // Enqueue the left child with horizontal distance hd - 1
            if (node->left) q.push({node->left, hd - 1});

            // Enqueue the right child with horizontal distance hd + 1
            if (node->right) q.push({node->right, hd + 1});
        }
    }

    // Concatenate the nodes from the map to form the result vector
    vector<int> ans;
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        for(auto i:it->second)
        {
            ans.push_back(i);
        }
    }
        // finally return the ans vector
        return ans;
    
    }
