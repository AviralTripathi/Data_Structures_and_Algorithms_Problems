Code with Explaination:

class Solution {
    private:
    int function(int index,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        // base case
        if(index>=coins.size() || amount <=0)
        // if the amount has become =0 that means that we have found the right answer
        // then return 0 or in other the amount is < 0 then return int-max-1
        // since we are supposed to find the minimum
        return (amount==0) ?0:INT_MAX-1;
        // intially before any recursive call we will be initially the dp array with 
        // -1
        // this is to avoid repetitive calls
        if(dp[index][amount]!=-1)
        return dp[index][amount];
        dp[index][amount]=-1;
        // now for any index if coins[index]
        if(coins[index] > amount)
        // condition for do not pick
        dp[index][amount]=function(index+1,amount,coins,dp);
        else
        {
            // now this means that coins[index] <=amount
            // since if coins[index] can be picked once then there is a possibility
            // that it can be picked again
            int pick=1+function(index,amount-coins[index],coins,dp);
            int notPick=function(index+1,amount,coins,dp);
            // take the minimum  of the two recurisve calls 
            dp[index][amount]=min(pick,notPick);
        }
        return dp[index][amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(13,vector<int>(10001,-1));
        int result=function(0,amount,coins,dp);
        return (result==INT_MAX-1)?-1:result;  
    }
};

Time Complexity: O(n*amount)

Space Complexity: O(n*amount)


Tabulation method:

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int function(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        // Base case
        if (amount == 0) return 0;
        if (index < 0 || amount < 0) return INT_MAX - 1;
        
        // If already computed, return the cached result
        if (dp[index][amount] != -1) return dp[index][amount];
        
        // Initialize the dp[index][amount] to INT_MAX - 1
        dp[index][amount] = INT_MAX - 1;
        
        if (coins[index] <= amount) {
            // Option to pick the coin
            int pick = 1 + function(index, amount - coins[index], coins, dp);
            // Option to not pick the coin
            int notPick = function(index - 1, amount, coins, dp);
            // Take the minimum of picking and not picking
            dp[index][amount] = min(pick, notPick);
        } else {
            // Option to not pick the coin if it's greater than the amount
            dp[index][amount] = function(index - 1, amount, coins, dp);
        }
        
        return dp[index][amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = function(n - 1, amount, coins, dp);
        return (result == INT_MAX - 1) ? -1 : result;
    }
};

Time Complexity: O(n*amount)

Space Complexity: O(n*amount)
