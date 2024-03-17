Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.


Intuition
Keeping two pointers i on the right and j on the left, whenever nums[i] = 0 increment k, once k > 1 (as only 1 zero is allowed to delete) we will set k = 1(i.e. considering current 0 at nums[i]) and incrementing j until previous 0 is not found, once previous is found increment j as we dont need that 0 at nums[j].Always storing i-j in ans i.e excluding 1 element that can be 1 or 0.

Approach
Sliding Window

Code:

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 0, count = 0;
        while (j < nums.size()) {
            if (nums[j] == 0)
                // increment count
                count++;
            // now we are checking this as it is given in the ques that we are
            // only allowed to delete 1 element
            if (count > 1) {
                // set count=1;
                count=1;
                while (i < j && nums[i] == 1)
                    // keep incrementing the left pointer in the start of the
                    // window
                    i++;
                i++;
            }
            ans = max(ans, j - i);
            j++;
        }
        return ans;
    }
};

Complexity
Time complexity:O(n)
Space complexity:O(1)

