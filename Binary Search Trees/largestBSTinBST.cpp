Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of the whole tree.
Examples: 
 

Input: 
      5
    /  \
   2    4
 /  \
1    3
Output: 3 
The following subtree is the 
maximum size BST subtree 
   2  
 /  \
1    3
Input: 
       50
     /    \
  30       60
 /  \     /  \ 
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the
maximum size BST subtree 
      60
     /  \ 
   45    70
        /  \
      65    80


Problem Statement:

  Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8


  // Code:

  class NodeValue
{
    public:
    int minNode,maxNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSize=maxSize;
    }
};

class Solution{
    private:
    NodeValue largestBSTSubtree_helper(Node* root)
    {
        if(!root)
        return NodeValue(INT_MAX,INT_MIN,0);
        auto left=largestBSTSubtree_helper(root->left);
        auto right=largestBSTSubtree_helper(root->right);
        if(left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);

        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize ,right.maxSize));
    }

    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBSTSubtree_helper(root).maxSize;
    }
};

Time Complexity:
Space Complexity:
