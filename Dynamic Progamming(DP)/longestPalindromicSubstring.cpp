Code with Explaination:

class Solution {
private:
    // Helper function to determine if s[i...j] is a palindrome
    bool solve(vector<vector<bool>>& dp, int i, int j, string& s) {
        if (i == j) {
            // Substring of length 1 is always a palindrome
            return dp[i][j] = true;
        }
        if (j - i == 1) {
            // Substring of length 2 is a palindrome if both characters are the
            // same
            return dp[i][j] = (s[i] == s[j]);
        }
        // For substrings longer than 2, check the first and last characters
        // and the palindromic status of the substring in between
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
            return dp[i][j] = true;
        } else {
            return dp[i][j] = false;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startIndex = 0;
        int maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                solve(dp, i, j, s);
                if (dp[i][j]) {
                    if (j - i + 1 > maxlen) {
                        startIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startIndex, maxlen);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
