You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106

Intuition
Sliding window with 1 single loop. This question is solved more than half year ago.

To make sliding window & honor the bit manipulation it is suggested to solve 3097. Shortest Subarray With OR at Least K II

Moving 2 pointers l, r like other sliding window questions in these days (but if nums[r] is outside of the bounds, moving l=r+1, i.e. skip it).

Keep nums[l..r] having the values among [minK, maxK]; if shrinking window by increasing l up to the k=min(mini, maxi) where mini & maxi is the the last index for minK or maxK resp., it is still a such array.

So, the increment for each iteration will be max((k-l+1),0)

Approach
Although sliding window, but the pattern in Leetcode 992. Subarrays with K Different Integers
must be modified a lot.

Set maxi=-1, mini=-1 to track the positions for the indices for ocurrences of maxK & minK.
Set l=0. Use a loop from r=0 to nums.size()-1:
x=nums[r]
if x exceeds the bounds, move l to r+1 & goto the next iteration
set maxi=r if x==maxK; or mini=r if x==minK
increment=max((min(maxi, mini)-l+1),0), which is the number of subarrays ending with index=r with all values in [minK, maxK]. Add it to ans
For better understanding the code, consider the testcasenums=[1,3,5,2,7,5,1,5,1,2] minK=1 maxK=5. Add some output to the submitted code to see the process

r=0, x=1,mini=0,maxi=-1,l=0
=> increment=0
r=1, x=3,mini=0,maxi=-1,l=0
=> increment=0
r=2, x=5,mini=0,maxi=2,l=0
=> increment=1
r=3, x=2,mini=0,maxi=2,l=0
=> increment=1
r=4, x=7 exceeds the bounds
r=5, x=5,mini=0,maxi=5,l=5
=> increment=0
r=6, x=1,mini=6,maxi=5,l=5
=> increment=1
r=7, x=5,mini=6,maxi=7,l=5
=> increment=2
r=8, x=1,mini=8,maxi=7,l=5
=> increment=3
r=9, x=2,mini=8,maxi=7,l=5
=> increment=3
ans=11


Code:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
                long long ans=0;
        int maxi=-1, mini=-1;
        int s=nums.size();
        for(int r=0, l=0; r<s; r++){
            int x=nums[r];
            if (x<minK ||x>maxK){// x exceeds the bound
                l=r+1; // move l to r+1
                continue;
            }
            if (x==maxK) maxi=r; // position for maxK
            if (x==minK) mini=r; // position for minK
            ans+=max((min(maxi, mini)-l+1),0);
        }
        return ans;

    }
};

Complexity Analysis:
Time complexity:
O(n)

Space Complexity:
O(1)
