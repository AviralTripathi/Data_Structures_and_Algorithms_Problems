Basically here the idea of the problem is that we have been given root's of the 2 trees and we are supposed to merge them and return the final BST.

-> the given 2 trees are BST in itself -so there inorder traversal would give us the all the elements of the trees in the sorted order

& that can be stored in a data structure  
-> eventually it becomes the problem of the 2 sorted arrays being given and we have to merge them and the merged array/vector should be obviously be in sorted 
nature.

  Problem Statement:

Given two BSTs, return elements of both BSTs in sorted form.


Example 1:

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
Example 2:

Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.


// Approach:

  -> make a function with the name of the inorder traversal and find the inorder traversal with the help of that function
-> in the already created function header now find the inorder traversal of both the given trees with root nodes root1 & root2
-> store the inorder traversal in the appropriate data structure
-> now apply the logic of the merging two sorted arrays and store them in the 3rd vector result
-> now simply return the result and that will be the required answer.

// Code:

class Solution
{
    public:
    void inorderTraversal(Node* root,vector<int> &result)
    {
        if(root==NULL)
        return;
        
        // recursively calling for the left subtree firstly
        inorderTraversal(root->left,result);
        result.push_back(root->data);
        inorderTraversal(root->right,result);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       // declaring a vector to print the final answer
       vector<int> result;
       vector<int> inorder1;
       vector<int> inorder2;
       
       // this will ensure the storing of the inorder traversal of the of the 2 trees with root1 & root2
       
       inorderTraversal(root1,inorder1);
       inorderTraversal(root2,inorder2);
       
       // since this is the inorder traversal of the bst is sorted in nature so therefore now we will
       // merge the sorted vectors inorder1 & inorder2 into a single vector result and the logic will be 
       // obviously same as the merging of the two sorted arrays
       
       int i=0,j=0;
       while(i<inorder1.size() && j<inorder2.size())
       {
           if(inorder1[i]<inorder2[j])
           result.push_back(inorder1[i++]);
           else
           result.push_back(inorder2[j++]);
           
       }
       
       // now if some elements are left in the inorder1 vector
       
       while(i<inorder1.size())
       result.push_back(inorder1[i++]);
       
       // now if some elements are left in the inorder2 vector
       
       while(j<inorder2.size())
       result.push_back(inorder2[j++]);
       
       
       // now result vector will be having the elements of both the BSTs in the sorted format
       // so we will simply return it
       
       return result;

    }
};

Time Complexity:
Space Complexity:
