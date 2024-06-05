Code:

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        // Initially, every element in dp is set to 1 because the minimum length
        // of an increasing subsequence ending at any index is at least 1 (the
        // element itself).

        vector<int> dp(
            n, 1); // dp[i] stores the length of the LIS ending at index i
        int maxLen = 1;
        // The outer loop (for (int i = 0; i < n; i++)) iterates over each
        // element of the array. The inner loop (for (int j = 0; j < i; j++))
        // checks all previous elements to see if they can be a part of a longer
        // increasing subsequence ending at arr[i].
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    //                     What dp[j] represents:

                    // dp[j] represents the length of the LIS ending at index j.
                    // By definition, dp[j] already includes arr[j] in the LIS
                    // sequence. Why dp[j] + 1:

                    // When we compare arr[i] with arr[j] (where j < i), and we
                    // find that arr[i] > arr[j], it means that arr[i] can
                    // follow arr[j] in the LIS. Therefore, the length of the
                    // LIS ending at i would be dp[j] + 1. By adding 1 to dp[j],
                    // we are extending the sequence that ends at j to include
                    // arr[i] as well. This is necessary because arr[i] is
                    // greater than arr[j], so it forms a valid extension of the
                    // LIS ending at j.
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};


Time Comlexity:
O(n^2)
Space Complexity: O(n)
