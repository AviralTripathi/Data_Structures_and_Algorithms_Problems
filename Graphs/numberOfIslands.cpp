class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        // mark the starting node of the dfs traversal as 1
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            // these are the local variables whoose existence will remain just
            // inside the while loop and therfore the will counter with the
            // formal parameters given in the function signature.
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse the neighbours of the popped element
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    // checking for the boundary conditions for nrow and ncol
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                        vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // computing the values of row & coloumn
        int n = grid.size();
        int m = grid[0].size();
        // creating a 2-D visited array
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


Time Complexity: O(N^2) since O(9*N^2) because the neighbours nested loops in total will be running for 9 tinmes but for every node we are checking for 8 
  directions and secondly when delrow=0 7 delcol=0 we are actually pointing to the same row and col for whe the bfs would have been intitated so that
won't be counted.
Space Complexity: O(N^2) space ouccpied by the visited array and recursive stack will be also be N^2 so O(N^2) +o(N^2)~~O(N^2)


2nd code is more optimized:

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



