Problem Statement:

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
  Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
  
Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1


Code: memorization

class Solution {
    private:
    int function(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0 || grid[i][j]==1)
        // then this cannot be a valid unique path
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=function(i-1,j,dp,grid);
        int left=function(i,j-1,dp,grid);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
        // here we are checking the case of whether the starting block has an obstacle or if the ending block has an obstacle then we don't a need a function
        // to find a valid path we can simply return 0;
        return 0;
        return function(n-1,m-1,dp,obstacleGrid);
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m) +O(n*m)


  Code: Tabulation
  
  class Solution {
private:
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            // here we are checking the case of whether the starting block has
            // an obstacle or if the ending block has an obstacle then we don't
            // a need a function to find a valid path we can simply return 0;
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // since as per the recursion and the memoization we know that i=0,j=0
        // will return us 1 and so we initialize it with 1.
        dp[0][0] = 1;
        for(int i=0;i<m;i++)
        {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)continue;
            else
            {
                int up=0;
                if(i>0 && obstacleGrid[i][j]!=1) up=dp[i-1][j];
                int left=0;
                if(j>0 && obstacleGrid[i][j]!=1) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        }
        return dp[m-1][n-1];
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m)
