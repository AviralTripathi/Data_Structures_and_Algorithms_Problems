You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105


Algorithm
Find the Maximum Element:

Find the maximum element (max_num) in the array nums.
Initialize Variables:

Initialize left, right to 0, count to 0, and ans to 0.
Sliding Window Technique:

Use a sliding window approach to iterate through nums.
Move right pointer from left to right.
Increment count if nums[right] equals max_num.
Count Subarrays:

If count >= k, calculate subarrays count:
Add nums.size() - right to ans.
This accounts for all subarrays ending at right with at least k occurrences of max_num.
Adjusting Window:

Shrink window from left if necessary:
Move left pointer rightwards.
Decrement count if nums[left] equals max_num.
Move Right Pointer:

Move right pointer to continue expanding the window.
Return Answer:

Return ans as the total count of subarrays satisfying the condition.

  Code:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // important to remember the syntax for finding the max element in
        // nums vector
        long long max_num=*max_element(nums.begin(),nums.end()),count=0;
        long long int left=0,right=0,ans=0;
        while(right<nums.size())
        {
            if(nums[right]==max_num)count++;
            while(count>=k)
            {
                if(nums[left]==max_num)count--;
                left++;
//                 Therefore, nums.size() - right calculates the number of subarrays that can be formed starting from the current right index until the end of the vector. This includes all subarrays ending at the right index and extending up to the last element of the vector.

// By adding this count to ans, we accumulate the total number of subarrays satisfying the condition where the count of the maximum element is at least k.
                ans+=nums.size()-right;
            }
            right++;
        }
        return ans;
    }
};

Complexity Analysis:

Time Complexity:

Space complexity:
