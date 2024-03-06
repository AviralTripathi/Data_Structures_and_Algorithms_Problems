Given a binary tree, check whether it is a mirror of itself.

For example, this binary tree is symmetric: 

     1
   /   \
  2     2
 / \   / \
3   4 4   3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3

  // here is the implementation for the above code

   bool isMirror(struct Node* root1,struct Node* root2)
    {
        // if both trees are empty then they are mirror images
        if(root1==NULL && root2==NULL)
        return 1;
        
        // now since both the trees are not empty so firstly for mirror images
        // the root's data should be same 
        // plus the left substree of the left tree & the right subtree of the right tree should be 
        // mirror images
        // the right subtree of the left tree & the left subtree of the right tree
        // should be mirror images
        // this can be checked recursively
        if(root1 && root2 && (root1->data==root2->data) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left))
        // this condition holds then symmetricity exists
        return 1;
        
        // if nothing has been returned till now then simply return false;
        return 0;
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // just simply call the isMirror function here
	    return isMirror(root,root);
    }


Time Complexity: O(N) // N=numbers of nodes in the tree
Space Complexity: O(h) // maximum height of the tree
