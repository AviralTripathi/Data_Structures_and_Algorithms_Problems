Code with Explanation:

// dp is (0-n-1) means not the i value but dp works in that way

class Solution {
    private:
    int function(int i,int n,vector<int> &c,vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e9;
        ans=c[n-1-i]+min(function(i-1,n,c,dp),function(i-2,n,c,dp));
        return dp[i]=ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1001,-1);
        int n=cost.size();
        // it is mentioned in the question that we can start from the 0th or the 
        // 1st step so in opposite n-1,n-2 and taking the minimum of that
        return min(function(n-1,n,cost,dp),function(n-2,n,cost,dp));
    }
};


// Time complexity: O(n)
// Space Complexity: O(n)
