The diameter/width of a tree is defined as the number of nodes on the longest path between two end nodes. 

The diagram below shows two trees each with a diameter of nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

// there are 2 approches to solve this partciular problem but the second one is the most efficient 

Algo:
The diameter of T’s left subtree.
The diameter of T’s right subtree.
The longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

Code:
// Time Complexity: O(N^2) Space Complexity: O(N) stack space
//   // longest path between the two leaf nodes through will be taking into account the height of BT
//   int height(Node* root)
//   {
//       //base case
//       if(root==NULL)
//       return 0;
      
//       return 1 + max(height(root->left),height(root->right));
      
//   }
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         // first check whether the tree is empty or not
//         if(root==NULL)
//         // there is no point for the diameter simply return null
//         return 0;
        
//         // get the height of the left and right subtrees
//         int lheight=height(root->left);
//         int rheight=height(root->right);
        
//         // get the diameter of the left and right subtress
//         int ldiameter=diameter(root->left);
//         int rdiameter=diameter(root->right);
        
//         // return the max of the following
        
//         // 1/ diameter of the left subtree
//         // 2 diameter of the right subtree
        
//         // height of the left subtree + height of the right subtree +1
        
//         return max(max(ldiameter,rdiameter),lheight+rheight+1);
//     }


More efficient apprach takes into account the fact that we don't need to put a separate function for the calculation of the heght instead we will be using
  the same and will be passing as well in that function:
rest all logic remains the same

Code:

int diameter_solve(Node* root,int* height)
{
    // height of the left and right subtree intially 
    int lh=0,rh=0;
    
    // diameter of the left and right subtree
    int ldiameter=0,rdiameter=0;
    
    // checking for the root being not equal to null
    if(root==NULL)
    {
        *height=0;
    return 0;
    }
    
    // calculation of the diameter of the left and right subtrees
    ldiameter=diameter_solve(root->left,&lh);
    rdiameter=diameter_solve(root->right,&rh);
    
    // height of the tree 
    *height=max(lh,rh)+1;
    
    // return the values by taking the max of the height along with the diameter through the proper
    // equation
    
    return max(lh+rh+1,max(ldiameter,rdiameter));
    
    
}
int diameter(Node*root)
{
    int height=0;
    diameter_solve(root,&height);
}

Time Complexity: O(N)
Space Complexity: O(N) due to recursive calls


