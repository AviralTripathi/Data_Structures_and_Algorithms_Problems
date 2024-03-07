Given a Binary Tree, The task is to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1. 

Examples:

Input:            20
                    /     \
                8         22
             /      \         \
          5         3        25
                   /    \      
              10       14

Output: 5, 10, 3, 14, 25.


  Create a map where the key is the horizontal distance and the value is a pair(a, b)
where a is the value of the node and b is the height of the node. 
  Perform a pre-order traversal of the tree. If the current node at a horizontal distance of 
h is the first we’ve seen, insert it into the map. Otherwise, compare the node with the 
existing one in map and if the height of the new node is greater, update the Map.

Follow the below steps to implement the idea:

Create a map where the key is the horizontal distance and the value is a pair(a, b) where a is the value of the node and b is the height of the node. 

Recursively apply Depth first search on the Tree starting from root node and keep 
a track of height curr and horizontal distance as hd of the current node with respect to root node as root node’s height is 0.
If there’s no node as value for horizontal distance hd in map then set map[hd] = make_pair(root -> data, curr).
Else store the pair value of mp[hd] in p. Then 
If p.second <= curr then set m[hd].second = curr and m[hd].first = root -> data
Call depth first search for left node of root node with height curr + 1 and horizontal distance as hd – 1 and right node of root node with height curr + 1 and horizontal distance as hd + 1
Base case would be to return when root is NULL.

  // here is the code for the same logic implenmented

    void solve(Node* root,int curr,int hd,map<int,pair<int,int>> &m)
  {
      // firstly check for the root being or not
      // Base Case
      if(root==NULL)
      return;
      // if node for a particular horizontal distance is not present
      if(m.find(hd)==m.end())
      {
          m[hd]=make_pair(root->data,curr);
          
      }
      else
      {
          // there is a particular node which exists for the horizontal distance
          pair<int,int> p=m[hd];
          if(p.second <= curr)
          {
              m[hd].second=curr;
              m[hd].first=root->data;
          }
          
      }
      // recurring for the left subtree
      solve(root->left,curr+1,hd-1,m);
      // recurring for the right subtree
      solve(root->right,curr+1,hd+1,m);
      
  }
    vector <int> bottomView(Node *root) {
        // declare a map first to pass it as an argument
        map<int,pair<int,int>> m;
        // declaring a vector to get the final answer and send it to main
        vector<int> ans;
        // initally both the curr and height of the root node will be zero
        solve(root,0,0,m);
        map<int,pair<int,int>>::iterator i;
        for(i=m.begin();i!=m.end();i++)
        {
            //becond the value stored in the map is of concern to us here in this function
            pair<int,int> p=i->second;
            ans.push_back(p.first);
        }
        // now simply return the ans vector
        return ans;
    }
Time Complexity: O(N*logN) // logN is extra factor because of using the map
Space Complexity: O(N); Auxillary Space
