You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


Code with explaination:

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            zero += (nums[i] == 0) ? 1 : 0;
        }

        if ((target + sum) % 2 != 0 || target + sum < 0) {
            return 0;
        }

        if ((target + sum) == 0) {
            return pow(2, zero);
        }

        int P = (target + sum) / 2;

        // DP table initialization
        vector<vector<int>> dp(nums.size() + 1, vector<int>(P + 1, 0));
        dp[0][0] =
            1; // Base case: There's one way to have sum 0 with 0 elements.

        // Fill the DP table
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= P; j++) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][P];
    }
};

// DP table dp is a 2D array where dp[i][j] represents the number of ways to
// achieve the sum j using the first i elements of the array. dp[0][0] is
// initialized to 1 because there is one way to achieve a sum of 0 with zero
// elements (the empty subset). DP Transition:

// For each element in the array, we update the DP table to reflect the number
// of ways to achieve each possible target sum using subsets of elements
// considered so far.

// here dp[i][j] represents the target sum that has been done uptill now till
// the ith index.

// We initialize a DP table dp where dp[i][j] represents the number of ways to
// achieve sum j using the first i elements of the array.

//         (target + sum) % 2 != 0: This condition checks whether
//         (target + sum) is odd. If it is odd, it's impossible to
//         partition the array into two subsets that differ by the
//         target value. This is because an odd number cannot be split
//         evenly into two integers. Therefore, if this condition is
//         true, the function returns 0.

// target + sum < 0: This checks if the sum of the target and the array
// sum is negative. If it's negative, it means the problem cannot be
// solved as there can't be a negative sum of subset elements. Thus, the
// function returns 0.

// sum + target == 0: This condition checks if the sum and target negate
// each other perfectly, resulting in zero. If this is true, the number
// of ways to achieve this is determined by the number of subsets of
// zeros, which is
// 2
// zero
// 2
// zero
//   (each zero can either be included or not in the subset).

// When the condition sum + target == 0 holds, it implies that the sum
// of all elements in the array is exactly equal to the absolute value
// of the target. In such a scenario, each subset solution that
// satisfies this condition can be doubled by considering the presence
// of zeros in the array. This is because zeros can be assigned either a
// + or a - sign and still contribute zero to the sum.

// we need the coloumns of th dp vector till target+sum becasue the part
// of 1 subset can stretch to (target+sum)/2;

// this is because let sum of the one of the subsets of '+' be p
// then next subset of '-' will sum of the nums vector s-p
// We need the difference between the sums of the two subsets to be
// equal to the target:


Time complexity: O(n*sum)
Space Complexity: O(n*m)


CODE OF TABULATION method:


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            zero += (nums[i] == 0) ? 1 : 0;
        }

        if ((target + sum) % 2 != 0 || target + sum < 0) {
            return 0;
        }

        if ((target + sum) == 0) {
            return pow(2, zero);
        }

        int P = (target + sum) / 2;

        // DP table initialization
        vector<vector<int>> dp(nums.size() + 1, vector<int>(P + 1, 0));
        dp[0][0] =
            1; // Base case: There's one way to have sum 0 with 0 elements.

        // Fill the DP table
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= P; j++) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][P];
    }
};

Time Complexity: O(n*sum)

Space Complexity: O(n*sum)
