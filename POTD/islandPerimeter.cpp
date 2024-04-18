You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.



Intuition 🌊
To determine the perimeter of the island, we need to count the number of edges that are exposed to water. We can achieve this by iterating over each land cell and checking its adjacent cells. If the adjacent cell is water or out of bounds, we increment the perimeter count.

Approach 🛶
Initialize two variables: islands to count the number of land cells encountered and neighbors to count the number of adjacent land cells.
Iterate over each cell of the grid.
For each land cell encountered, increment the islands count.
Check the adjacent cells (up and left) and increment the neighbors count accordingly.
Finally, return the total perimeter count using the formula islands * 4 - neighbors * 2.
Complexity Analysis 📊
Time complexity: O(N×M), where NNN is the number of rows and MMM is the number of columns in the grid.
Space complexity: O(1)


  Code:

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0;
        int neighbors = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        neighbors++;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        neighbors++;
                    }
                }
            }
        }

        return islands * 4 - neighbors * 2;
    }
};
