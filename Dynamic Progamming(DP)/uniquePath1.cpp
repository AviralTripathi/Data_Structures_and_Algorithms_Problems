Problem Statement:

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
  
Example 1:
Input: m = 3, n = 7
Output: 28
  
Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


  Code: memoization

  class Solution {
    private:
    int function(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        // this means that this path has taken us to out-of-boundary situation.
        return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=function(i-1,j,dp);
        int left=function(i,j-1,dp);
        // count the number of ways to reach index (i,j) from (0,0).
        dp[i][j]=up+left;
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // passing the parameters such as index(m-1,n-1) since memoization is
        // a top-down based approach and alogwith that passing the dp vector
        return function(m-1,n-1,dp);
    }
};

Timne Complexity: O(n*m)

Space Complexity: O(n*m) +O(n*m)

  Tabulation Code:

// now in-order to use the tabulation method since it is the bottom-up based approach
// so the last element dp[m-1][n-1] will be having the final answer
class Solution {
public:
    int uniquePaths(int m, int n) {
        // creating a 2-D dp array and initialize it with 0
        vector<vector<int>> dp(m,vector<int>(n,0));
        // since as per the recursion and the memoization we know that i=0,j=0
        // will return us 1 and so we initialize it with 1.
        dp[0][0]=1;
        // for every row there are coloumns from 0-n-1
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)continue;
                // doing this since this has been already initialized
                else
                {
                    // instead of passing the parameters recursively inside a 
                    // function , we will store the answer inside the dp vector
                    int up=0;
                    if(i>0) up=dp[i-1][j];
                    int left=0;
                    // these conditions have been used here since we are using 
                    // indexes like i-1 && j-1 so in order to avoid the 
                    // out-of bounds error
                    if(j>0) left=dp[i][j-1];
                    // to get the total number of ways adding both the type of ways
                    dp[i][j]=up+left;
                }
            }
        }
        // returning the last index since it will be storing the answer
        return dp[m-1][n-1];
    }
};

Time Complexity: O(n*m)
Space Compexity: O(n*m)
