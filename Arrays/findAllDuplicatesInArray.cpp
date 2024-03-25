Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.


Approach
I will add zero in the last nums as a dumy node and I will iterate twice.

During the first iteration, I make all elements are in their correct positions. By 'correct position,' I mean that each element is located at its 
corresponding index in the sequence.

In the second iteration, I will check for any elements that are not in their correct positions. If an element is found to be out of place,
  it indicates duplication, and that element will be added to the result vector."

  Code:

  class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(0);
        vector<int> res;
        for(int i=0;i<=n;i++)
        {
            while(nums[i]!=nums[nums[i]])
            swap(nums[i],nums[nums[i]]);
        }
        for(int i=0;i<=n;i++)
        {
            if(nums[i]!=i)
            res.push_back(nums[i]);
        }
        return res;
    }
};
  
Complexity
Time complexity: O(n)
Space complexity: O(1)
