Explanation of the code:

In the "Partition Equal Subset Sum" problem, the goal is to determine if a given array can be partitioned into two subsets with equal sum. The conditions sum % 2 == 0 and related checks are crucial for solving this problem efficiently. Here's a detailed explanation of these conditions and their importance:

Why Check if sum % 2 == 0?
Total Sum Evenness:
Condition: if (sum % 2 != 0) return false;
Reason: For an array to be partitioned into two subsets with equal sum, the total sum of the array must be even.
Explanation: If the total sum is odd, it is impossible to divide it into two equal integer parts. For example, if the sum is 15, it cannot be split into two equal subsets, because 15 divided by 2 equals 7.5, which is not an integer. Hence, if the total sum is odd, the function immediately returns false.
Why Initialize target as sum / 2?
Target Sum:
Calculation: int target = sum / 2;
Reason: If the total sum is even, then each subset must sum to sum / 2 to form two equal subsets.
Explanation: For instance, if the total sum is 20, each subset must sum to 10 (since 20 / 2 = 10). Therefore, the problem reduces to finding whether there exists a subset of the array that sums to target.
Recursive Function Explanation
Recursive Function:
The function function(int index, int target, vector<int> &arr, vector<vector<int>> &dp) recursively checks whether a subset with sum equal to target can be formed using elements up to the given index.

Base Cases:

if (target == 0) return true;: If the target sum is 0, it means a valid subset has been found.
if (index == 0) return target == arr[index];: If we are at the first element (index == 0), check if it is equal to the target. If yes, return true.
Memoization Check:

if (dp[index][target] != -1) return dp[index][target];: If the result for dp[index][target] is already computed, return the stored result to avoid redundant computations.
Recursive Cases:

Include Current Element:
if (arr[index] <= target) { take = function(index - 1, target - arr[index], arr, dp); }
Include the current element in the subset and check if the remaining sum (target - arr[index]) can be formed with the previous elements.
Exclude Current Element:
bool notTake = function(index - 1, target, arr, dp);
Exclude the current element and check if the target sum can be formed with the previous elements.
Store and Return Result:

return dp[index][target] = take || notTake;
Store the result in dp[index][target] and return whether a valid subset was found by either including or excluding the current element.



Code:

class Solution {
    private:
    bool function(int index,int target,vector<int> &arr,vector<vector<int>> &dp)
    {
        // base case
        if (target==0)
        return true;
        if(index==0) return target==arr[index];
        if(dp[index][target]!=-1)
        return dp[index][target];
        bool take=false;
        if(arr[index] <= target)
        {
            take=function(index-1,target-arr[index],arr,dp);
        }
        bool notTake=function(index-1,target,arr,dp);
        return dp[index][target]=take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int k;
        if(sum%2==0)
        k=sum/2; else
        return false;
        if(n==1)
        return false;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        // since this parameter is being fo the i/p nums vector
        return  function(n-1,k,nums,dp);
    }
};

Time Complexity: O(n*k) where k is the target sum 

Space Complexity: O(n*k) + O(n) // O(n) is recursion stack space ~ O(n*k)
Summary:
