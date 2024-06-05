Explaination:

Initialization:

n = values.size() gives the number of vertices in the polygon.
dp(n, vector<int>(n, -1)) initializes a DP table with -1 to indicate that the result for that state has not been computed yet.
Base Case:

if (i >= j) return 0;: If there are less than three vertices, no triangle can be formed, so the score is 0.
Memoization Check:

if (dp[i][j] != -1) return dp[i][j];: If we have already computed the result for dp[i][j], return it to avoid redundant calculations.
Recurrence Relation:

Iterate through each possible vertex k between i and j to form a triangle.
tempAns is the sum of the scores of the subproblems plus the score of the current triangle.
values[i - 1] * values[k] * values[j] computes the score of the triangle formed by vertices at i-1, k, and j.
ans = min(ans, tempAns) keeps track of the minimum score.
Memoization:

dp[i][j] = ans stores the result in the DP table for future reference.
Function Call:

return function(1, n - 1, values, dp); starts the recursion with the first and last vertices of the polygon.
This approach ensures that we consider all possible triangulations and find the one with the minimum score efficiently using dynamic programming and memoization.


  Code:

  class Solution {
private:
    int function(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        if (i >= j)
            return 0; // Base case: No polygon can be formed

        if (dp[i][j] != -1)
            return dp[i][j]; // Return the memoized result

        int ans = INT_MAX;

        // Try every possible vertex k to split the polygon
        for (int k = i; k < j; ++k) {
            int tempAns = function(i, k, values, dp) +
                          function(k + 1, j, values, dp) +
                          values[i - 1] * values[k] * values[j];

            ans = min(ans, tempAns); // Take the minimum score
        }

        return dp[i][j] = ans; // Memoize the result
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize DP table
        return function(1, n - 1, values,
                        dp); // Start from the first and last vertex
    }
};


Time Complexity: O(n^3)

Space Complexity: O(n^2)



