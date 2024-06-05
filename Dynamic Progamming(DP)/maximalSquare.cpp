Code with Explaination:

class Solution {
public:
    // Helper function to recursively find the largest square submatrix of '1's
    int helper(vector<vector<char>>& matrix, int i, int j, int row, int col,
               int& maxi, vector<vector<int>>& dp) {
        // Base case: If we are out of bounds, return 0
        if (i >= row || j >= col) {
            return 0;
        }

        // If the value is already computed, return it from dp (memoization)
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        char ch = '1';

        // Recursive calls to explore right, diagonal, and down directions
        int right =
            helper(matrix, i, j + 1, row, col, maxi, dp); // Move to the right
        int diagonal = helper(matrix, i + 1, j + 1, row, col, maxi,
                              dp); // Move diagonally down-right
        int down =
            helper(matrix, i + 1, j, row, col, maxi, dp); // Move downward

        // If the current cell is '1', calculate the size of the largest square
        // ending at this cell
        if (matrix[i][j] == ch) {
            // Size of the largest square ending at (i, j)
            int ans = 1 + min(right, min(down, diagonal));
            // Update the maximum square size found so far
            maxi = max(maxi, ans);
            // Memoize the result
            return dp[i][j] = ans;
        } else {
            // If the current cell is '0', return 0 (no square can end here)
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Check for edge cases
        if (matrix.empty())
            return 0;

        // Initialize the dp array for memoization, initially set to -1
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));

        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0; // Variable to store the maximum square size found

        // Start recursion from the top-left corner of the matrix
        int ans = helper(matrix, 0, 0, row, col, maxi, dp);

        // Return the area of the largest square found
        return maxi * maxi;
    }
};

// Time Complexity:  O(n*m)

// Space Complexity: O(n*m)

// Understanding the Problem:

// We are tasked with finding the largest square of '1's in the matrix.
// The size of the square is determined by the smallest side (either right,
// diagonal, or down) that allows for the square to extend one more cell. Using
// min:

// Each of the right, diagonal, and down values represents the maximum size of a
// square of '1's that can be formed ending at the current cell (i, j). To
// extend this square to include the current cell (i, j), we need to ensure that
// we can form squares of '1's in all three directions. Why min?:

// The size of the square is limited by the smallest of these three values. This
// is because we can only form a square of size min(right, min(down, diagonal))
// ending at the current cell (i, j). Logical Flow:

// If we can form squares of '1's in all three directions (right, diagonal,
// down), then the size of the square ending at (i, j) is 1 + min(right,
// min(down, diagonal)). If any of these values is 0 (meaning we cannot form a
// square in that direction), then min(right, min(down, diagonal)) will be 0,
// and thus the size of the square ending at (i, j) will also be 1.
