Problem Statement:

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

  Code:

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY, endX, endY;
        int emptyCount = 0; // To count the number of empty cells

        // Find the starting and ending points, and count the empty cells
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                } else if (grid[i][j] == 0) {
                    ++emptyCount;
                }
            }
        }

        // Use DFS to count all unique paths
        return dfs(grid, startX, startY, endX, endY,
                   emptyCount + 1); // +1 to include the starting cell
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int endX, int endY,
            int remaining) {
        // If out of bounds or it's an obstacle, return 0
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
            grid[x][y] == -1) {
            return 0;
        }

        // If it's the ending cell and we've visited all cells, return 1
        if (x == endX && y == endY) {
            return remaining == 0 ? 1 : 0;
        }

        // Mark the cell as visited by setting it to -1
        grid[x][y] = -1;
        int paths = 0;

        // Move in all four directions
        paths += dfs(grid, x + 1, y, endX, endY, remaining - 1);
        paths += dfs(grid, x - 1, y, endX, endY, remaining - 1);
        paths += dfs(grid, x, y + 1, endX, endY, remaining - 1);
        paths += dfs(grid, x, y - 1, endX, endY, remaining - 1);

        // Unmark the cell (backtrack)
        // In the depth-first search (DFS) algorithm with backtracking, we
        // unmark the cell after all four recursive calls to explore all
        // possible paths starting from the current cell. This is crucial for
        // ensuring that we explore every potential path and correctly count the
        // number of valid paths that visit each cell exactly once.
        grid[x][y] = 0;

        return paths;
    }
};

Time Complexity: O(4^(m*n))
Space Complexity; O(m*n) due to recursion stack space
