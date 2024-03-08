Given a Binary Search Tree (BST) and a positive integer k, find the k’th largest element in the Binary Search Tree. 
For example, in the following BST, if k = 3, then output should be 14, and if k = 5, then output should be 10. 

Approach: 

The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
The reverse inorder traversal traverses all nodes in decreasing order, i.e, visit the right node then centre then left and continue traversing the nodes recursively.
While doing the traversal, keep track of the count of nodes visited so far.
When the count becomes equal to k, stop the traversal and print the key.

Code:

class Solution
{
    public:
    // function to help solve for the kth largest element in bst
    void solve(Node* root,int K,int &c,int & ans)
    {
        //base case
        if(root==NULL || c>K)
        return;
        
        // since we have to traverse the inorder traversal in the decreasing order i.e first
        // right,node(root),left
        solve(root->right,K,c,ans);
        // keep the track of the nodes visited so far
        c++;
        // if c becomes equal to k then this is the kth largest element
        if(c==K)
        ans=root->data;
        
        // recur for the left subtree
        solve(root->left,K,c,ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans=0;
        int c=0;
        solve(root,K,c,ans);
        return ans;
    }
};

Time Complexity: O(N) // in worst case from the given code it would have to traverse total of n times when k=n
Space Complexity/Auxillary Space: O(h) // max recursion stack space with height h of the given binary tree
