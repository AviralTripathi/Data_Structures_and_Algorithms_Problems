Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Intuition
The problem requires finding the maximum length of a contiguous subarray with an equal number of 0s and 1s. To achieve this, we can utilize the concept of prefix sums. Whenever we encounter 
an equal number of 0s and 1s, the sum of the elements from the start of the array up to that point will be the same as the sum from that point to the current index. By keeping track of the 
first occurrence of each sum encountered, we can calculate the length of the subarray and update the maximum length whenever we find a longer subarray.

Approach
We will use a hashmap to store the sum as the key and the index of its first occurrence as the value. We'll initialize the hashmap with a sum of 0 at index -1 to handle the edge case 
  where the subarray starts from the beginning of the array. Then, we'll iterate through the array, updating the sum based on the current element (increment if it's 1, decrement if it's 0). 
  If we encounter the same sum again, it indicates that the subarray between the previous occurrence and the current index has an equal number of 0s and 1s. We'll calculate the length of this
  subarray and update the maximum length accordingly. At each step, we'll update the hashmap with the sum and its index. Finally, 
  we'll return the maximum length found.

  Code:

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxLength=0;
        int sum=0;
        // initialize the sum  0 with index that will be value -1
        mp[0]=-1;
        // iterate through the whole nums array
        for(int i=0;i<nums.size();i++)
        {
            // while computing the sum initially we will increment for  1
            // and decrement for sum 0
            sum+=(nums[i]==1)?1:-1;
            // we will check for the sum that if it has been encountered again
            // or not. If it has been encountered again then simply that means
            // that between it's previous occurence and this index it contains 
            // equal number of 0s and 1s
            if(mp.find(sum)!=mp.end())
            // update the maxLength
            maxLength=max(maxLength,i-mp[sum]);
            else
            // simply the insert key value pair for the computed sum and it's index
            mp[sum]=i;
        }
        // finally retutn the maxLength variable which will be maimum length of the
        // contiguous array
        return maxLength;
    }
};

Complexity
Time complexity:
O(n), where n is the size of the input array nums. We iterate through the array once.
Space complexity:
O(n) in the worst case. The hashmap can store up to n distinct sums.
