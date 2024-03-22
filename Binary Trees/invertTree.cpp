Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Code:(multiple ways)

  class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        return root;
        swap(root->left,root->right);
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        return root;
        //swapping after the recursive calls have been made would also result in 
        // the same output
    }
};

2nd Method:
dfs-iterative

class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    stack<TreeNode *> s({root});
    while (!s.empty()) {
      TreeNode *current = s.top(); s.pop();
      if (!current) continue;
      swap(current->left, current->right);
      s.push(current->left), s.push(current->right);
    }
    return root;
  }

3rd Method:
bfs iterative

class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    queue<TreeNode *> q({root});
    TreeNode *current;

    while (!q.empty()) {
      current = q.front(), q.pop();
      if (!current) continue;
      swap(current->left, current->right);
      q.push(current->left), q.push(current->right);
    }
    return root;
  }
};
};
