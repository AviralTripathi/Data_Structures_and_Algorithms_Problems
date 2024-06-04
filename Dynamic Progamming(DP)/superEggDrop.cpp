Code:

// here in this case along with dp concept of binary search is being used
class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= k; i++)
            dp[i][0] = 0, dp[i][1] = 1;
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0, dp[1][i] = i;
        for (int i = 2; i < k + 1; i++) {
            for (int j = 2; j < n + 1; j++) {
                int l = 1, h = j, temp = 0, ans = INT_MAX;
                while (l <= h) {
                    int mid = (l + h) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];
                    // this one is being done because of the current cell
                    temp = 1 + max(left, right);
                    // Implication of left < right
                    // Egg Breaks (Less Effort): If dropping the egg from floor
                    // mid results in fewer attempts if the egg breaks, then the
                    // more challenging scenario (higher number of attempts) is
                    // when the egg does not break. Need to Search Higher
                    // Floors: Since the harder case is when the egg does not
                    // break (more attempts), we should focus on the higher
                    // floors above mid because this is where more attempts will
                    // be needed. Hence, we adjust the search range to the upper
                    // half.

                    if (left < right)
                        l = mid + 1;
                    else
                        h = mid - 1;
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[k][n];
    }
};


Time Complexity: O(k*n)
Space Complexity: O(k*n) 
