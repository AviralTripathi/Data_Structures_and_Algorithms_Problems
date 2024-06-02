Problem Statement:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


  Explanation:

Intuition
When robbing houses, we must ensure that we do not rob two adjacent houses to avoid detection. Therefore, at each house(n), we have a choice: either rob that house(n) and the one before the previous house(n-2), or skip the current house and just rob the previous one(n-1). This strategy helps us maximize our total loot while maintaining the constraint of not robbing adjacent houses.

Approach
I used Bottom-up Iterative Dynamic programming approach to solve this problem:
dp is a 1D array where dp[i] stores the maximum amount robbed till ith house.

Base cases:
dp[0] = nums[0]; (as there is only one house)
dp[1] = max(nums[0], nums[1]); (as we can rob only one house among 0th and 1st house)
Recursive formula:
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
Traverse from i = 2 to n-1, and calculate dp[i] iteratively using the above formula.
Complexity
Time complexity: O(n) - As we traverse the array once.
Space complexity: O(n) - As we are using the dp array to store the values.


Code:

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            // since if the size is of 1 then simply value of the money stored
            // in that house will be the maximum amount of money that can be
            // robbed
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            //             At each house i, you have two choices:
            // Do not rob the current house (i): If you choose not to rob the
            // current house, the maximum amount of money you can have is the
            // same as the maximum amount robbed up to the previous house i-1,
            // which is dp[i-1]. Rob the current house (i): If you choose to rob
            // the current house, you cannot rob the previous house (i-1).
            // Therefore, the total money robbed will be the money in the
            // current house (nums[i]) plus the maximum amount robbed up to the
            // house before the previous one (i-2), which is dp[i-2] + nums[i].

            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
