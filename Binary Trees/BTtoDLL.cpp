Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right
pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
  The order of nodes in DLL must be the same as in Inorder for the given Binary Tree. 
  The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.



Algo:

// If the left subtree exists, process the left subtree
// Recursively convert the left subtree to DLL.
// Then find the inorder predecessor of the root in the left subtree (the inorder predecessor is the rightmost node in the left subtree).
// Make the inorder predecessor as the previous root and the root as the next in order predecessor.
//  If the right subtree exists, process the right subtree (Below 3 steps are similar to the left subtree).
// Recursively convert the right subtree to DLL.
// Then find the inorder successor of the root in the right subtree (in order the successor is the leftmost node in the right subtree).
// Make the inorder successor as the next root and the root as the previous inorder successor.
// Find the leftmost node and return it (the leftmost node is always the head of a converted DLL).

Implementation of the above code:

// we will be making a utility function to help us in solving the problem
    pair<Node*, Node*> bToDLL_solve(Node* root)
    {
        if(root == NULL)
            return {NULL, NULL};
        
        // Convert left and right subtrees
        auto leftList = bToDLL_solve(root->left);
        auto rightList = bToDLL_solve(root->right);
        
        // Connect root with its left subtree's rightmost node
        if(leftList.second != NULL) {
            leftList.second->right = root;
            root->left = leftList.second;
        }
        
        // Connect root with its right subtree's leftmost node
        if(rightList.first != NULL) {
            rightList.first->left = root;
            root->right = rightList.first;
        }
        
        // Return the leftmost and rightmost nodes of the current subtree
        return {(leftList.first != NULL) ? leftList.first : root,
                (rightList.second != NULL) ? rightList.second : root};
    }

    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // base case
        if(root==NULL)
        return root;
        // Get the leftmost and rightmost nodes of the doubly linked list
        auto result = bToDLL_solve(root);
        
        // Find the leftmost node (head) of the doubly linked list
        while(result.first->left != NULL)
            result.first = result.first->left;
        
        return result.first;    
    }


Time Complexity: O(N)
Space Complexity: O(1)
