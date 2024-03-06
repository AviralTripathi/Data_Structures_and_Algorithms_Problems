Step 1: Start
Step 2: Create a function named “getLeafCount”of int return type that take node as input parameter.
Step 3: Set the conditions:  
       a. If the node is NULL, return 0.
       b. If the node has no left or right child, return 1.
       c. Recursively call “getLeafCount” on the left and right child nodes if the node has left or right children, and then return  the total of the results.
Step 4: End

int countLeaves(Node* root)
{
  // firstly checking if the root is null or not
  if(root==NULL)
  return 0;
  else if(root->left==NULL && root->right==NULL)
  {
      // then this is certainly a leaf node
      return 1;
  }
  else
  {
      // the particular node is of some other kind
      // the recursivly call for both the subtrees of the root node
      return countLeaves(root->left)+countLeaves(root->right);
  }
}

Time Complexity (TC): O(N)
Space Complexity: O(1) if we don't consider the stack space but if we do it the O(h) where h is the height of the BT
