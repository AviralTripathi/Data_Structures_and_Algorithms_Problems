Problem Statement:

You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.


Example 1:

Input: n = 2
Output: 2
Explanation: We can drop the first egg from floor 1 and the second egg from floor 2.
If the first egg breaks, we know that f = 0.
If the second egg breaks but the first egg didn't, we know that f = 1.
Otherwise, if both eggs survive, we know that f = 2.
Example 2:

Input: n = 100
Output: 14
Explanation: One optimal strategy is:
- Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8. Drop the 2nd egg starting from floor 1 and going up one at a time to find f within 8 more drops. Total drops is 1 + 8 = 9.
- If the 1st egg does not break, drop the 1st egg again at floor 22. If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting from floor 10 and going up one at a time to find f within 12 more drops. Total drops is 2 + 12 = 14.
- If the 1st egg does not break again, follow a similar process dropping the 1st egg from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
Regardless of the outcome, it takes at most 14 drops to determine f.

Code:

class Solution {
    private:
    int function(int e,int f,vector<vector<int>> &dp)
    {
        // base condtion
        if(f==0 || f==1)
        // if there are no floors or a single floor then f attempts will be needed
        return f;
        if(e==1)
        {
            // if we are only left or have 1 egg then we have to check sequentially
            // from one floor to another.
            // so total number of attempts made will be = to the number of floors.
            return f;
        }
        if(dp[e][f]!=-1)
        return dp[e][f];
        int mini=INT_MAX;
        int low,high;
        for(int k=1;k<=f;k++)
        {
            // for the case when the egg is dropped from the kth floor and it breaks
            if(dp[e-1][k-1]!=-1)
            low=dp[e-1][k-1];
            else
            low=function(e-1,k-1,dp);
            dp[e-1][k-1]=low;
            // for the case when the egg is dropped from the kth floor and it does 
            // not breaks
            if(dp[e][f-k]!=-1)
            high=dp[e][f-k];
            else
            {
            high=function(e,f-k,dp);
            dp[e][f-k]=high;
            }
            int temp=1+max(low,high);
            mini=min(mini,temp);
        }
        return dp[e][f]=mini;
    }

public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(1001,-1));
        return function(2,n,dp);
    }
};

Time Complexity: O(n*m)

Space Complexity: O(n*m)
