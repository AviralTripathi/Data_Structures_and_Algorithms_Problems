A Binary Search Tree (BST) is a node-based binary tree data structure that has the following properties. 

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Each node (item in the tree) has a distinct key.

// Follow the below steps to solve the problem:

If the current node is null then return true
If the value of the left child of the node is greater than or equal to the current node then return false
If the value of the right child of the node is less than or equal to the current node then return false
If the left subtree or the right subtree is not a BST then return false
Else return true


Code:

int maxValue(Node* root)
    {
        if(root==NULL)
        return INT_MIN;
        int value=root->data;
        int leftMax=maxValue(root->left);
        int rightMax=maxValue(root->right);
        return max(value,max(leftMax,rightMax));
    }
    // for the minvalue
    int minValue(Node* root)
    {
        if(root==NULL)
        return INT_MAX;
        int value=root->data;
        // recursively calling for the min calculation of min value 
        int leftMin=minValue(root->left);
        int rightMin=minValue(root->right);
        return min(value,min(leftMin,rightMin));
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // if node==null then return true
        if(root==NULL)
        return true;
        
        if(root->left!=NULL && maxValue(root->left) >= root->data)
        return false;
        
        if(root->right!=NULL && minValue(root->right) <= root->data)
        return false;
        
        // if the left subtree or the right subtree is not a BST in itself then return false
        if(!isBST(root->left) || !isBST(root->right))
        return false;
        
        // else if nothing has been returned by a func. uptill now then return true
        return true;
    }

Time Complexity:  O(N2), As we visit every node just once and our helper method also takes O(N) time, so overall time complexity becomes O(N) * O(N) = O(N2)
Space Complexity: Auxiliary Space: O(H), Where H is the height of the binary tree, and the extra space is used due to the function call stack.
