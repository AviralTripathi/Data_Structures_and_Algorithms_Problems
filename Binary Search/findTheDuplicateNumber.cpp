Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

Approach:
  
-> Since the numbers in the array are in the range [1, n] and there's only one repeated number, we can use binary search to find the duplicate number.
-> We perform binary search on the range [1, n], and for each mid value, we count the number of elements in the array that are less than or equal to the mid value.
-> If the count is greater than mid, then the duplicate lies in the left half of the range; otherwise, it lies in the right half.
-> If there's no duplicate, in a sorted array, we would expect nums[i] to be equal to i + 1 for each i. However, with a duplicate, there will be more than i + 1 numbers less than or equal to mid.
-> We continue narrowing down the range until we find the duplicate number.

// we will be using xor for this operation
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=1;
        int right=nums.size()-1;
        while(left < right)
        {
            int mid=left + (right-left)/2;
            int count=0;

            // count the numbers less than or equal to mid
            for(int num:nums)
            {
                if(num<=mid)
                count++;
            }
            // if the count is greater than mid, the duplicate lies in the left
            // half because since we are applying the binary search  and since
            // the for the vector nums till mid will be treated a separate
            // vector and the element will be in the range 1-mid since for each
            // sub vector each integer in the range (1-mid) so if the numbers
            // less than is more than the mid then simply the duplicate 
            // lies in the left half and the number of elements would be greater
            // than mid since for the whole vector if the numbers are in the 
            // range [1-n] then the length of the nums vector is n
            // here [1-n] is MONTONIC SEARCH SPACE on which BINARY SEARCH
            // will be applied
            if(count > mid)
            right=mid;
            else
            left=mid+1;
        }
        return left;    
        }
};
  
Complexity
Time complexity: O(NlogN)
Space complexity: O(1)
