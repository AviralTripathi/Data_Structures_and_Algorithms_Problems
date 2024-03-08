Given a Binary Tree, the task is to print the Level order traversal of the Binary Tree in spiral form i.e, alternate order.
//   Follow the below steps to Implement the idea:

// Initialize a variable h to store the height of the binary tree.
// Initialize a variable i, and ltr = false.
// Traverse a loop from 1 till h:
// Print the level order traversal of given traversal using below recursive function:
// printGivenLevel(tree, level, ltr)
// if tree is NULL then return;
// if level is 1, then
// print(tree->data);
// else if level greater than 1, then
// if(ltr)
// printGivenLevel(tree->left, level-1, ltr);
// printGivenLevel(tree->right, level-1, ltr);
//    else
// printGivenLevel(tree->right, level-1, ltr);
// printGivenLevel(tree->left, level-1, ltr);
// Update ltr = !ltr

  // below is the implementation of the code

  // function to compute the height of the tree
int height(Node* root)
{
    if(!root)
    return 0;
    
    return 1+max(height(root->left),height(root->right));
}


// function to store the data or print it in sprial mannner through level wise sequenceing
void printGivenLevel(Node*root,int level,bool flag,vector<int> &ans)
{
    if(root==NULL)
    return;
    if(level==1)
    // then this is the first level so we will simply store the root's data
    ans.push_back(root->data);
    else if(level > 1)
    {
        if(flag)
        {
            printGivenLevel(root->left,level-1,flag,ans);
            printGivenLevel(root->right,level-1,flag,ans);
        }
        else
        {
            printGivenLevel(root->right,level-1,flag,ans);
            printGivenLevel(root->left,level-1,flag,ans);
        }
    }
}

void printSpiral(Node* root,vector<int> &ans)
{
    // call for the height of the tree computation
    int h=height(root);
    int i;
    bool flag=false;
    // will iterate over from 1 to h
    for(int i=1;i<=h;i++)
    {
        //call for the printgiven level function
        printGivenLevel(root,i,flag,ans);
        
        // we have to reverse the flag value so that in next level it gets printed in opposite order
        flag=!flag;
    }
}
//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    printSpiral(root,ans);
    return ans;
}

Time Complexity: O(N^2) // where N is the number of nodes in the tree
Space Complexity: O(N) // for recursive stack space and auxillary space O(N) since we have used  a vector
