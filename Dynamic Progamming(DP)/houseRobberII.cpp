Problem Statement:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3


  Explanation same as the house robber I just that here in the since it is in a cicurlar fashion so we can't select both first and the last element in our answer at the same time since they are adjacent so it is 
   somewhat in circular fashion. So we will making the call for the nums array after removing the first element and then after removing the last element and taking the maximum of them as our final answer.


Code:

class Solution {
public:
    int help(vector<int>& nums) {
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
    int rob(vector<int> &nums)
    {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1)
        return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            temp1.push_back(nums[i]);
            if(i!=n-1)
            temp2.push_back(nums[i]);

        }
        return max(help(temp1),help(temp2));
    }
};

Time Compexity: O(N)

Space Complexity: O(N)
