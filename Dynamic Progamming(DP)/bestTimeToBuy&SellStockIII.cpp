Approach :
We just to need to build the recursive solution after that recursive -> iterative conversion and optimisations can be done easily.
Everyday, We have two choices : Buy/Sell this stock OR ignore and move to the next one.
Along with day, we also need to maintain a transactionsLeft variable which will tell us how many transactions are remaining and it will be of which type (Buy or Sell) and According to that we will make recursive calls and calculate the answer
We can do atmost 4 transactions (Buy, Sell, Buy, Sell) in this order.
// No transaction today :
	ans1 = solve(day + 1, transactionsLeft); 
// transaction today :
   bool buy = (transactionsLeft % 2 == 0);
	if(buy == true) {
		ans2 = -prices[day] + solve(day + 1, transactionsLeft - 1);
	}else{
		ans2 = prices[day] + solve(day + 1, transactionsLeft - 1);
	}
Now Choosing the best one among them and returning the required answer.
We will stop the recursion when day >= prices.size() or transactionsLeft == 0 and return 0.


  Code:

class Solution {
private:
    int function(vector<int>& prices, int day, int transactionLeft, vector<vector<int>>& dp) {
        // Base cases
        if (day >= prices.size() || transactionLeft == 0) {
            return 0;
        }
        
        // Check if dp[day][transactionLeft] is already computed
        if (dp[day][transactionLeft] != -1) {
            return dp[day][transactionLeft];
        }
        
        // Choice 1: Do not make a transaction today
        int ans1 = function(prices, day + 1, transactionLeft, dp);
        
        // Choice 2: Perform a transaction today
        int ans2 = 0;
        bool buy = (transactionLeft % 2 == 0); // If transactionLeft is even, it means we are in a position to buy
        
        if (buy) {
            // Buy stock today
            ans2 = -prices[day] + function(prices, day + 1, transactionLeft - 1, dp);
        } else {
            // Sell stock today
            ans2 = prices[day] + function(prices, day + 1, transactionLeft - 1, dp);
        }
        
        // Store the result in dp[day][transactionLeft]
        dp[day][transactionLeft] = max(ans1, ans2);
        
        return dp[day][transactionLeft];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(5, -1));
        
        // Starting day of analyzing the transactions is 0th
        return function(prices, 0, 4, dp); // 4 because we have 4 transactions allowed
    }
};

Time Complexity: O(N)
Space Complexity: O(N)
