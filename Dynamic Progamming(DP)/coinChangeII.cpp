Code with Explaination:

class Solution {
private:
    int function(int index, int amount, vector<int> &coins,
                 vector<vector<int>> &dp) {
                    // base case
                    if(amount==0)
                    return 1;
                    if(amount < 0 || index <0) return 0;
                    if(dp[index][amount]!=-1) return dp[index][amount];
                    int pick=function(index,amount-coins[index],coins,dp);
                    int notPick=function(index-1,amount,coins,dp);
                    return dp[index][amount]=pick+notPick;
                 }

public:
    int change(int amount,vector<int> &coins) {
        int n = coins.size();
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = function(n - 1, amount, coins, dp);
        return result;
    }
};


Time Complexity: O(n*amount)

Space Complexity: O(n*amount)


Tabulation Method:

class Solution {
public:
    int change(int amount,vector<int> &coins) {
        int n = coins.size();
        // Initialize dp array with -1
        // here declared with amount + 1 since maximum amount that go upto = amount
        // already passed as a parameter
        vector<vector<int>> dp(301, vector<int>(5001, 0));
        // if the amount is 0 then no coins are needed
        // and to get the amount we have just got one way and this is intuitive which
        // is relaized from the memoised solution
        // there can be only 1 case like this
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        // now here we are iterating over the dp vector
        // we are trying to fill the dp table 

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<amount+1;j++)
            // here coins[i-j] <=j means that understand this through the recrusion 
            // way that the function call f(i,j) with amount j and index is it 
            // possible to make that amount from given coins and then we fill
            // the dp cell signigfying the recursive call
            if(coins[i-1]<=j)
            dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
        return dp[n][amount];
    }
};

Time Complexity: O(n*amount)

Space Complexity: O(n*amount)
