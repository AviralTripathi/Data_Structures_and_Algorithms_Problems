Code with tabulation:

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // logic of the question is very same just like the memoization and the 
        // recursive way but all the recrusive calls have been replced by dp vector
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

Time Complexity: O(m*n)
Space Complexity: O(m*n)

Code with memoization:

class Solution {
private:
    int function(string& text1, string& text2, int m, int n,
                 vector<vector<int>>& dp) {
        if (m == 0 || n == 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (text1[m - 1] == text2[n - 1]) {
            // here we can pass m,n as parameters since here we are itreating to
            // fill the dp vector
            dp[m][n] = 1 + function(text1, text2, m - 1, n - 1, dp);
        } else
            //         Character Mismatch: If the characters text1[m-1] and
            //         text2[n-1] are not equal, then we have two choices:

            // Exclude the current character of text1 and find LCS for
            // text1[0...m-2] and text2[0...n-1]. Exclude the current character
            // of text2 and find LCS for text1[0...m-1] and text2[0...n-2]. We
            // take the maximum of these two possibilities.

            dp[m][n] = max(function(text1, text2, m - 1, n, dp),
                           function(text1, text2, m, n - 1, dp));
        return dp[m][n];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return function(text1, text2, m, n, dp);
    }
};


Time Complexity: O(m*n)
Space Complexity: O(m*n)
