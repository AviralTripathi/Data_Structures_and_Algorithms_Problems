Code with Explaination:

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        
        // If the lengths don't add up, return false
        if (m + n != l) {
            return false;
        }
        
        // Create a 2D DP table with dimensions (m+1) x (n+1)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Initialize the starting point
        dp[0][0] = true;
        
        // Fill the first column: s1 characters should match s3
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        
        // Fill the first row: s2 characters should match s3
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        
        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        
        // The result is in the bottom-right cell
        return dp[m][n];
    }
};

// Explanation of the code:
// 1. Check if the total length of s1 and s2 matches the length of s3. If not, return false.
// 2. Initialize a 2D DP table where dp[i][j] indicates whether s3[0...i+j-1] can be formed by interleaving s1[0...i-1] and s2[0...j-1].
// 3. Set dp[0][0] to true because an empty s1 and empty s2 can form an empty s3.
// 4. Fill the first column where only s1 contributes to forming s3.
// 5. Fill the first row where only s2 contributes to forming s3.
// 6. Use a nested loop to fill the rest of the DP table by checking if the current character of s3 matches the current character of s1 or s2 and update the DP table accordingly.
// 7. Return the value in dp[m][n], which indicates whether s3 can be formed by interleaving s1 and s2.

// Time complexity: O(m * n)
// Space complexity: O(m * n)


// remember this since dp is the replacement for the function so dp[i-j][j] && this
// dp[i][j-1] represents the recursive call for the next iteration
