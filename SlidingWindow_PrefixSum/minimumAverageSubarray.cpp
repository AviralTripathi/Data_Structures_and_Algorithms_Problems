You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
  Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

  Approach:

Certainly! Let's go through the code line by line:

class Solution {: This line begins the definition of a C++ class named Solution.

public:: This keyword specifies that the members following it (in this case, the findMaxAverage function) are accessible from outside the class.

double findMaxAverage(vector<int>& nums, int k) {: This line declares the function findMaxAverage which takes two parameters - a vector of integers (nums) and an integer (k). The function returns a double.

double ans = 0;: Initializes a variable ans of type double and sets its initial value to 0. This variable will be used to store the maximum average.

double sum = 0;: Initializes a variable sum of type double to store the sum of elements in the sliding window.

for(int i =0; i < k; i++) {: This loop iterates over the first k elements of the input vector nums and calculates the initial sum.

sum += nums[i];: Adds the current element of nums to the sum.
ans = sum;: Sets the initial value of ans to the sum calculated in the previous loop.

for(int i = k; i < nums.size(); i++) {: This loop iterates from index k to the end of the vector nums and updates the sum and ans for each window.

sum += nums[i];: Adds the current element to the sum.

sum -= nums[i - k];: Subtracts the element that is no longer part of the window (sliding window technique).

ans = max(ans, sum);: Updates ans with the maximum value between its current value and the current sum.

return ans/k ;: Returns the maximum average, which is the final value of ans divided by k.

This code effectively finds the maximum average of a subarray of length k in the given vector nums using a sliding window approach.

Code:
  class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double ans=0;
       double sum=0;
       for(int i=0;i<k;i++)
       {
        sum+=nums[i];
       } 
       ans=sum;
       for(int i=k;i<nums.size();i++)
       {
        sum+=nums[i];
        sum-=nums[i-k];
        // checking whether the computed sum 
        ans=max(ans,sum);
       }
       // compute the average of the elements of that window of size k whose sum
       // is maximum
       return ans/k;
    }
};
  
Complexity
Time complexity:0(N)
Space complexity:0(1)

