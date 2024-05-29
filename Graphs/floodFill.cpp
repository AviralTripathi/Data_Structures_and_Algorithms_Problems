class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // Define the 4 possible directions (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            
            // Traverse the neighbors of the popped element
            for (auto dir : directions) {
                int nrow = curRow + dir.first;
                int ncol = curCol + dir.second;
                
                // Checking for the boundary conditions for nrow and ncol
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};


Time Complexity: O(N*M) since at max there will be all the pixels in the image that are of the same colour and for each pixel there will be 4 neighbours 
O(N*M*4) makes it O(N*M)
Space Complexity: for space we are using ans matrix to store the reformed image matrix and recurisve stack space is equal to the O(N*M) since there will at
max N*M dfs calls if all the nodes are of the same of the starting node since they all would have to be changed so:
O(N*M) +O(N*M)=O(N*M)
