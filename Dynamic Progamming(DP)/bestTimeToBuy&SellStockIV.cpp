Code with Explaination:

class Solution {
private:
    // Function to calculate maximum profit with at most k transactions
    // prices: array of stock prices
    // k: maximum number of transactions allowed
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        // Edge case: If there are no prices or if k is 0, return 0
        if (n == 0 || k == 0) {
            return 0;
        }
        
        // If k is greater than or equal to n/2, we can do as many transactions as we want
        // because we can complete one transaction (buy and sell) in one day.
        if (k >= n/2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) {
                    maxProfit += prices[i] - prices[i-1];
                }
            }
            return maxProfit;
        }
        
        // Initialize dp array with -1
        // dp[i][j]: Maximum profit using at most j transactions up to day i
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        // Helper function to calculate maximum profit using at most k transactions up to day i
        function(prices, 0, k, dp);
        
        // The maximum profit using at most k transactions up to day 0 is the answer
        return dp[0][k];
    }
    
    // Helper function to calculate maximum profit with at most k transactions starting from day 'day'
    // prices: array of stock prices
    // day: current day
    // k: maximum number of transactions allowed
    // dp: memoization table
    int function(vector<int>& prices, int day, int k, vector<vector<int>>& dp) {
        // Base case
        if (day >= prices.size() || k == 0) {
            return 0;
        }
        
        // Check if dp[day][k] is already computed
        if (dp[day][k] != -1) {
            return dp[day][k];
        }
        
        // Choice 1: Do not make a transaction today
        int ans1 = function(prices, day + 1, k, dp);
        
        // Choice 2: Perform a transaction today
        int ans2 = 0;
        
        // Find the maximum profit with (k-1) transactions till today and buy on day i
        for (int i = day + 1; i < prices.size(); ++i) {
            ans2 = max(ans2, prices[i] - prices[day] + function(prices, i + 1, k - 1, dp));
        }
        
        // Store the result in dp[day][k]
        dp[day][k] = max(ans1, ans2);
        
        return dp[day][k];
    }

public:
    // Public function to calculate maximum profit with at most k transactions
    // k: maximum number of transactions allowed
    // prices: array of stock prices
    int maxProfit(int k, vector<int>& prices) {
        return maxProfit(prices, k);
    }
};

// Time Complexity: O(n*k)

// space complexity: O(n*k)
