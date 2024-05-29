// User function Template for C++

class Solution {
    private:
    // here we also need to carry the base coordinates
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,vector<pair<int,int>> 
    &v,int row0,int col0)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
        // once we are done with this we have to travel upwards downwards,leftwards and rightwards
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,grid,vis,v,row0,col0);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        // n*m
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    // we will also be passing a vector to the dfs function to store the coordinates
                    // of the 1's forming the island and will store it inside a set.
                    // n*m*4
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,v,i,j);
                    // once the dfs call is over we will be simply storing the vector inside the set.
                    s.insert(v);
                }
            }
        }
        return s.size();
        // so the time complexity of the code will be n*mlog(n*m)+n*m*4;
    }
};

Time Complexity: O(N) + O(N+2E)
Space Complexity: O(N)
