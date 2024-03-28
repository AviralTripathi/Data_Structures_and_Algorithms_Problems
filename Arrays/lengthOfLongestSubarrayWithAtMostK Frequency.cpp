You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
Example 3:

Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= nums.length


Approach 1: Counting and Sliding Window
Intuition
In approaching the given problem, the key objective is to find the length of the longest contiguous subarray, termed as "good," based on the constraint that the frequency of each element within this subarray should be less than or equal to a given value, denoted as k. The solution lies in understanding the nature of the array and devising a strategy to efficiently identify and track the eligible subarrays.

A crucial insight is recognizing that the goodness of a subarray is intricately tied to the frequency distribution of its elements. To efficiently capture this information, a mechanism is needed to monitor the frequency of each encountered element during the traversal of the array.

Given the need to find the longest good subarray, an intuitive approach is to utilize a sliding window technique. This involves defining two pointers, which dynamically adjust their positions based on the evolving conditions of the array. The sliding window allows us to efficiently maintain the goodness of the subarray by adjusting its size dynamically as we iterate over nums.

Now, let's delve into the loop structure. The loop will iterate through each element of the array, updating the frequency of each encountered element. This counter is pivotal, as it stores the essential information about the array's composition.

Within this loop, there is a conditional check to ensure that the frequency of the current element does not violate the given constraint k. If, at any point, the frequency surpasses k, it indicates a breach of the goodness condition. To rectify this, a second pointer is used to shrink the window from the left, effectively reducing the frequency of elements until the goodness condition is restored.

The decision to check frequency[nums[end]] > k in the while loop is grounded in the fact that frequency[nums[end]] has already been updated within the for loop. This means that only the frequency of the current element (nums[end]) could be greater than k and thus is being assessed for compliance with the goodness condition. This sequence in the code ensures that the check is precise, targeting the specific element causing the potential violation.

Throughout this process, the length of the current subarray meeting the goodness criteria is continuously updated. The maximum length encountered so far is stored as the final answer.

Current

Algorithm
Initialize variables ans and start. Variable ans will store the length of the longest good subarray, and start will be used to track the start of the current subarray.
Create an unordered map named frequency to keep track of the frequency of elements in the array.
Iterate through the elements of the input array nums using a for loop with index end.
Increment the frequency count of the current element nums[end] in the frequency dictionary.
Enter a while loop to handle the condition where the frequency of the current element nums[end] exceeds the given threshold k. In this loop:
Move the start of the subarray (start) one position forward.
Decrement the frequency count of the element at index start (start of the current subarray) in the frequency dictionary.
Repeat this process until the frequency of nums[end] in the current subarray becomes less than or equal to k.
Update the length of the longest good subarray (ans) by taking the maximum of its current value and the difference between the current index end and the start index start.
Continue the loop until all elements in the array are processed.
Return the final value of ans as the length of the longest good subarray.



ode:

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> frequency;
        
        for (int end = 0; end < nums.size(); end++) {
            frequency[nums[end]]++;
            while (frequency[nums[end]] > k) {
                start++;
                frequency[nums[start]]--;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};

complexity analysis:

