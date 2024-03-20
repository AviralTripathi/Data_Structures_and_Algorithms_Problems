Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Code:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // firstly computing the size of the nums vector
        int n=nums.size();
        // now defining two pointers
        int i=0,j=0;
        // now will iterate through the whole array and the moment we find a non
        // zero number keeping fixed the ith pointer at the 0 index itself we
        // will swap the values at both the pointers
        for(;j<n;j++)
        {
            if(nums[j]!=0)
            {
                // simply swap the values the index i & j
                swap(nums[i],nums[j]);
                // move the ith pointer ahead to the next index so that to fill the 
                // position of that index
                // please note here i is actually being used to fill up the 
                // each and every position in the initial array itself but 
                // with the required modification as per given in the question
                i++;
            }
        }
    }
};
