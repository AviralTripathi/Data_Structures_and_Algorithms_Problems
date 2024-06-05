Intuition :
Here we have to find the minimum edit distance problem between two strings word1 and word2.
The minimum edit distance is defined as the minimum number of operations required to transform one string into another.
Approach :
The approach here that I am using is dynamic programming. The idea is to build a 2D matrix dp where dp[i][j] represents the minimum number of operations required to transform the substring word1[0...i-1] into the substring word2[0...j-1].
How is Matrix built :
The matrix is built iteratively using the following recurrence relation:
If word1[i-1] == word2[j-1], then dp[i][j] = dp[i-1][j-1]. That is, no operation is required because the characters at positions i-1 and j-1 are already the same.
Otherwise, dp[i][j] is the minimum of the following three values:
dp[i-1][j-1] + 1: replace the character at position i-1 in word1 with the character at position j-1 in word2.
dp[i-1][j] + 1: delete the character at position i-1 in word1.
dp[i][j-1] + 1: insert the character at position j-1 in word2 into word1 at position i.
The base cases are:
dp[i][0] = i: transforming word1[0...i-1] into an empty string requires i deletions.
dp[0][j] = j: transforming an empty string into word2[0...j-1] requires j insertions.
Final Step :
Finally, return dp[m][n], which represents the minimum number of operations required to transform word1 into word2, where m is the length of word1 and n is the length of word2.
Complexity
Time complexity : O(mn)
Space complexity : O(mn)


  Code:

  class Solution {
public:
    int minDistance(string word1, string word2) {
        // first word length;
        int m = word1.length();
        // second word length
        int n = word2.length();
        // dp[i][j]: minimum number of operations to convert word1[0....i] to
        // word2 [0.....j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // no operations is required
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                        // for all these it will look into the previous state
                        // of the dp-table
                        // sequence in min replace->delete->insert
                    // here +1 signifies one replacement/deletion/insertion plus
                    // the cost to match the rest
                }
            }
        }
        return dp[m][n];
    }
};
