Code with Explaination:

class Solution {
private:
    // here creating a 1-D because there is only one varying parameter
    // note here n does not represent the size but it it represents the
    // first place where are u standing and to track further movements
    int function(int n, vector<int>& dp) {
        // base case
        // Base Cases: if (n == 0) and if (n == 1) are handled to return 1
        // because there's only one way to stand still or take one step.

        if (n <= 1)
            return 1;
        // to avoid repetitive recursion calls
        // here dp[i]= reprents number of steps away from the 0th step
        if (dp[n] != -1)
            return dp[n];

        // here we will be storing the sum of the two recursive calls
        // one for 1 step taken and other for 2 steps taken
        dp[n] = function(n - 1, dp) + function(n - 2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return function(n, dp);
    }
};


Time Complexity:  O(n)

Space Complexity: O(n) -recursion stack space + O(n) -dp vector so total space complexity: O(n)
