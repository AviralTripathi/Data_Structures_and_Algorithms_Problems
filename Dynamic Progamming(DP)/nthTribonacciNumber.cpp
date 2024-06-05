Code with Explanation:

class Solution {
    private:
    int generate(int n,vector<int> &dp)
    {
        // base case
        if(n<=1)
        return n;
        if(n==2)
        return 1;

        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=generate(n-1,dp) +generate(n-2,dp) + generate(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int> dp(38,-1);
        return generate(n,dp);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
