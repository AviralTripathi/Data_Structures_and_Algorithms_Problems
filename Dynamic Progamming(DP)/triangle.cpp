Code with Explaination:

class Solution {
private:
    
    // Function to solve the problem using tabulation
    // triangle: the input triangle of numbers
    // n: number of rows in the triangle
    int solveTabulation(vector<vector<int>>& triangle, int n) {
        // Initialize a DP table with dimensions (n) x (n)
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the bottom row of the DP table with values from the triangle
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }
        
        // Iterate from the second last row up to the first row
        for (int i = n - 2; i >= 0; i--) {
            // Iterate from the last column up to the current row's index
            for (int j = i; j >= 0; j--) {
                // Calculate the minimum path sum at the current cell
                int first = triangle[i][j] + dp[i + 1][j];    // Move down to the same column
                int second = triangle[i][j] + dp[i + 1][j + 1];  // Move down to the next column
                dp[i][j] = min(first, second);  // Choose the smaller path sum
            }
        }

        // Return the minimum path sum starting from the top of the triangle
        return dp[0][0];
    }

public:
    // Main function to calculate the minimum path sum
    // triangle: the input triangle of numbers
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();  // Number of rows in the triangle
        
        // Call the tabulation function to get the result
        int ans = solveTabulation(triangle, n);
        
        // Return the minimum path sum
        return ans;
    }
};


// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
