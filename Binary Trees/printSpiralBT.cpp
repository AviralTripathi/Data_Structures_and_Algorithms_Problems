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



  2nd Method:

Sure, let's break down the provided code:

Function Purpose:

The function zigzagLevelOrder aims to perform a level order traversal of a binary tree in a zigzag manner. That means it traverses each level of the tree from left to right in alternating directions (left to right for odd levels, right to left for even levels).
Algorithm:

The function utilizes Breadth First Search (BFS) to traverse the binary tree level by level.
It maintains a queue q1 to keep track of the nodes at each level.
At each level:
It iterates through the nodes in the queue.
For each node, it adds its value to the current level's vector lvl.
It also enqueues the left and right child of the current node if they exist.
After processing all nodes at the current level, it appends the current level's vector lvl to the result vector res.
Additionally, it reverses the vector lvl if the flagRev is true, indicating that the traversal direction should be reversed.
The flagRev is toggled after processing each level to ensure zigzag traversal.
Variable Explanation:

queue<TreeNode*> q1: Queue to store the nodes of the binary tree level by level.
vector<vector<int>> res: Vector of vectors to store the zigzag level order traversal result.
bool flagRev: Flag to indicate whether the traversal direction should be reversed for the next level.
Function Execution:

The function starts by checking if the root node is NULL. If so, it returns an empty result vector res.
It enqueues the root node into the queue q1.
It then enters the main loop, which continues until the queue q1 becomes empty.
Inside the loop, it processes each level of the tree, enqueuing child nodes and adding values to the current level's vector.
After processing each level, it appends the current level's vector to the result vector res.
Finally, it returns the result vector res, which contains the zigzag level order traversal of the binary tree.

Code:

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Using Breadth First Search (BFS)
        queue<TreeNode*> q1;
        vector<vector<int>> res;
        bool flagRev = false;
        if (!root)
            return res;

        q1.push(root);

        while (!q1.empty()) {
            int size = q1.size();
            vector<int> lvl;

            while (size--) {
                TreeNode* curr = q1.front();
                q1.pop();

                if (curr->left)
                    q1.push(curr->left);
                if (curr->right)
                    q1.push(curr->right);

                lvl.push_back(curr->val);
            }

            if (flagRev)
                reverse(begin(lvl), end(lvl));
            flagRev = !flagRev;
            res.push_back(lvl);
        }

        return res;
    }
};


Time Complexity: O(N)
Space Complexity: O(N)
