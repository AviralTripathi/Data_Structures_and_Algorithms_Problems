Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

For the following input tree, output should be 9, 19, 42.
9 is sum of 1, 3 and 5.
19 is sum of 2, 6, 4 and 7.
42 is sum of 9, 10, 11 and 12.

Example 1:

Input:
         4
       /   \
      1     3
           /
          3
Output: 
7 4 
Example 2:

Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
Output: 
12 15 3

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105
0 <= data of each node <= 104



Code:

class Solution {
  public:
  void solve(Node*root, map<int,int>&mp, int level){
        if(!root) return;
        mp[level]+=root->data;
        
        solve(root->left, mp, level+1);
        solve(root->right, mp, level);
        
        return;
    }
    vector<int> diagonalSum(Node* root) {
        map<int,int>mp;
        solve(root, mp, 0);
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

Complexity Analysis:
