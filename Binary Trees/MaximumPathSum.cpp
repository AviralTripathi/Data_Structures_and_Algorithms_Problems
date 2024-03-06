Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another. 

The maximum sum path may or may not go through the root. For example, in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10). Expected time complexity is O(n). If one side of the root is empty, then the function should return minus infinite (INT_MIN in case of C/C++)

tree

We can find the maximum sum using single traversal of binary tree. The idea is to maintain two values in recursive calls

(Note: If the tree is right-most or left-most tree then first we have to adjust the tree such that both the right and left are not null. Left-most means if the right of super root of the tree is null and right-most tree means if left of  super root of the tree is null.) 

Maximum root to leaf path sum for the subtree rooted under current node. 
The maximum path sum between leaves (desired output).
For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, and compare the sum with maximum path sum found so far.


  //here is ghe implementation of the above information

int   solve(Node* root,int &res)
{
    // firstly handle the base cases
    if(root==NULL)
    return 0;
    if(!root->left && !root->right)
    // this means the tree has got just one element present inside the tree
    return root->data;
    
    // now we will be recurisvely calling for left and right subtree and will computing the maximum sum 
    // for the left and right subtrees resp.
    int ls=solve(root->left,res);
    int rs=solve(root->right,res);
    
    // if both the children exist for the root node
    if(root->left && root->right)
    {
        // update for the result
        res=max(res,ls+rs+root->data);
        
        // finally return the max path sum for the whole tree
        return max(ls,rs)+root->data;
    }
    
    // if any of the subtree does not exist
    
    return (!root->left)?rs+root->data:ls+root->data;
}
    int maxPathSum(Node* root)
    {
        // declaring a variable to get the final answer
        int res=INT_MIN;
        // here will be calling the maxPath sum function 
        int val = solve(root,res);
        
        if(root->left && root->right)
        return res;
        // this we have done since we do have to make the subtrees of the root node existing throughtout 
        // the show
        return max(res,val);
    }


Time Complexity: O(n) //n=number of nodes in  a tree
Space Complexity: O(n)
