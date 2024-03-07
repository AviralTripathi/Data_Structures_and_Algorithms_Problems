Given a Binary Tree, the task is to print the left view of the Binary Tree. The left view of a Binary Tree is a set of leftmost nodes for every level.

Examples: 

Input: 
                   4
                /   \
              5     2
                   /   \
                3     1
              /  \
           6    7

Output: 4 5 3 6


// 1st Method to print the left view of the binary tree

//   Keep track of the level of a node by passing the level as a parameter to all recursive calls and also 
// keep track of the maximum level. Whenever, we see a node whose level is more than maximum level so far,
// we print the node because this is the first node in its level 

// Note: We traverse the left subtree before right subtree. 

  // here is the implementation of the following code

  void solve(Node* root,int level ,int* maxLevel,vector<int> &ans)
{
    // firstly check whether the root is null or not
    if(root==NULL)
    return;
    
    if(level > *maxLevel)
    {
        ans.push_back(root->data);
        *maxLevel=level;
    }
    // now recrusively call for the left & right subtrees
    
    //left subtree
    solve(root->left,level+1,maxLevel,ans);
    //right subtree
    solve(root->right,level+1,maxLevel,ans);
}
vector<int> leftView(Node *root)
{
   // declaring a vector to store the final answer
   vector<int> ans;
   // in case of understanding the level switch or when the first node of the level is unconsideration
   // we will be using a variable to determin what is the maximum level uptill now
   int maxLevel=0;
   // firstly checking for the root being null or not
   if(root==NULL)
   return ans;
   // now calling for the solve function made above
   solve(root,1,&maxLevel,ans);
   return ans;
}

Time Complexity: O(N) // this is simply the traversal of the tree so the time complexity is equal to the number of nodes in the tree.
Space Complexity: O(h) // due to the stack space of the recusive call,where h is the height of the binary tree

  2nd Method

// using level order traversal

// Follow the below step to Implement the idea:

// Do level order traversal of the tree.
// For each level keep a track of the current level and print the first encountered node of this level.
// Move to the next level.

// implementation of the following code

void printLeftView(Node* root) 
{ 
    if (!root) 
        return; 
 
    queue<Node*> q; 
    q.push(root); 
 
    while (!q.empty()) 
    {     
        // number of nodes at current level 
        int n = q.size(); 
         
        // Traverse all nodes of current level 
        for(int i = 1; i <= n; i++) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
                 
            // Print the left most element 
            // at the level 
            if (i == 1) 
                cout<<temp->data<<" "; 
             
            // Add left node to queue 
            if (temp->left != NULL) 
                q.push(temp->left); 
 
            // Add right node to queue 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    } 
}   

Time Complexity: O(N) where n is equal to the number of nodes in the binary tree
Space Complexity:O(N) in the worst case the auxillary space that we are using the queue ds.
