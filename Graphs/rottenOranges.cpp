class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize the visited array with zeros
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Queue to perform BFS, store {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        
        // Find all the starting points (rotten oranges) and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as visited and rotten
                }
            }
        }
        
        // To keep track of the maximum time taken to rot all oranges
        int tm = 0;
        
        // Direction vectors for the 4 possible movements (up, right, down, left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // Perform BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            
            // Check all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // Check for valid cell and if it's a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    // Mark as visited (rotten)
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        
        // Check if there's any fresh orange left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }
        
        return tm;
    }
};

Time Complexity:

Space Complexity:
