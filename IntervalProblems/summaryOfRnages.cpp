You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


Approach
Using 2 Pointers to mark the prevIndex and currIndex Of the list
Find the length of the list using the 2 pointer and generate the required list accordingly

Code:

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        int prevIndex=0;
        for(int i=1;i<=n;i++)
        {
            // if the two numbers are not adjacent
            if(i<n && nums[i]==nums[i-1]+1)
            continue;
            else
            {
                // store the current index as i-1
                int currIndex=i-1;
                if(currIndex==prevIndex)
                // if the range has only one element,add it to the result
                ans.push_back(to_string(nums[prevIndex]));
                else
                // if the range has more than 1 element add the range to the 
                // result
                ans.push_back(to_string(nums[prevIndex])+"->"+to_string(nums[currIndex]));
            }
            // update the previous index to the current index
            prevIndex=i;
        }
        // finally return the ans vector which will be having the summaray of 
        // all the values of the nums vector;
        return ans;
    }
};

Complexity:

Time Complexity: O(n)
Space Complexity: O(1)
