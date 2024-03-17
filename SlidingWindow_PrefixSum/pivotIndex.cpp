Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0



Code:

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(),totalSum=0;
        vector<int> prefix_sum(n+1,0);
        // Example 1
        // pref = [0, 1, 8, 11, 17, 22, 28]
        // totalSum = 28
        for(int i=0;i<n;i++)
        {
            prefix_sum[i+1]=prefix_sum[i]+nums[i];
            totalSum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            // if the current number is nums[i], 
            // then we can get the left part easily - just pref[i]
            // the right part would be the total sum - pref[i] - the current number
            int leftSum=prefix_sum[i];
            int rightSum=totalSum-prefix_sum[i]-nums[i];
            // if the left sum is same as the right sum,
            // then i is the pivot index
            if(leftSum==rightSum)
            return i;
        }
        // no such index exists return -1;
        return -1;
    }
};


Time Complexity:
Space Complexity:
