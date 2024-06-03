Problem Statement:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

  Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200


Code:

  // here we are using memoization and in that we will be following bottom up dp
class Solution {
    private:
    int function(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        //base case
        if(i==0 && j==0)
        // this is done here so when it (0,0) then it simply the value stored in that
        // cell
        return grid[i][j];
       if(i<0 || j<0)
       // then simply 1e9 will be returned
       return 1e9;
        // avoiding repetitive calls
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j]+function(i-1,j,grid,dp);
        int left=grid[i][j]+function(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return function(m-1,n-1,grid,dp);
    }
};

Time Complexity: O(n*m)

Space Complexity: O(n*m)+O(n*m)




  Tabulation:

Code:

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // intially the first cell of the first element of the grid vector.
        // this is done based on the recrurrence relation obtained through recursion
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) continue;
                else
                {
                    // unlike the previous case of unique path here the up and left 
                    // variable should be initialized to the value of the grid[i][j]
                    // this is done if it choses the upward direction
                    int up=grid[i][j];
                    // storing the value in the up variable
                    // here in this case we have to add up the value obtained in 
                    // the path
                    if(i>0)
                     up+=dp[i-1][j];
                     else
                     // 1e9 is the maximum that the integer can hold or for which
                     // it is defined
                     up+=1e9;
                    // as this for the case if it choses to take the left direction
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    // now else is the case that are being written here because
                    // just in case the direction in which the movement is being done
                    // make take it out of bounds so in such cases the value that
                    // left will have will be maximum i.e INT_MAX
                    else
                    left+=1e9;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m) recursive stack space has been removed.
