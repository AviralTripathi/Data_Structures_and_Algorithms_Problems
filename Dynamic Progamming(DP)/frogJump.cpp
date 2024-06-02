Problem Statement:

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.



Explanation:

Approach (Recursion + Memoization)
int dp[2001][2001];: This declares a 2D array named dp to store the results of subproblems. It has dimensions [2001][2001], which seem to be chosen based on the constraints of the problem.

unordered_map<int, int> ump;: This unordered map is used to store the index of each stone. The stone value is the key, and the index is the value. This map is useful for quick lookups to determine if a stone exists at a certain position.

bool solve(vector& s, int x, int i): This is the main recursive function that aims to solve whether the frog can cross the river based on the given conditions.
s is the array of stone positions.
x is the last jump length made by the frog.
i is the current index of the frog on the stone array.

The function starts by checking if the frog is on the last stone (i == s.size() - 1). If true, it returns true because the frog has successfully crossed the river.

The function then checks if the result for the current subproblem is already stored in the DP array (dp[i][x]). If yes, it returns the precomputed result.

If the above conditions are not met, it proceeds to check whether the frog can make a valid jump of length x to the next stone. If so, it explores three possibilities:
Jumping with length x - 1.
Jumping with length x.
Jumping with length x + 1.
If any of these jumps are successful (solve returns true), it means the frog can cross the river, and the function stores true in the DP array for this subproblem.

If no valid jump is possible, the function stores false in the DP array for this subproblem and returns false.

The canCross function initializes the DP array with -1 values using memset. Then, it populates the ump map with stone positions and their corresponding indices.

Finally, the canCross function calls the solve function with the starting parameters and returns its result.

Complexity
Time complexity: O(n^2)
Space Complexity: O(n^2)

  Code:
class Solution {
private:
    // here i is the initial position of the stone x is the number of length of
    // the jump in units

    bool solve(vector<int> &stones, int x, int i, vector<vector<int>> &dp,
               unordered_map<int, int>& track) {
        if (i ==stones.size() - 1)
            return true;
        if (dp[i][x] != -1) 
            return dp[i][x];
            if (x > 0 && track.find(stones[i] + x) != track.end()) {
                if (solve(stones, x - 1, track[stones[i] + x],dp,track) ||
                    solve(stones, x, track[stones[i] + x],dp,track) ||
                    solve(stones, x + 1, track[stones[i] + x],dp,track))
                    // here we have gone for i,x since i is the position of the 
                    // stone and for dp vector 2 variable are their in the problem
                    return dp[i][x]=true;
            }
            return dp[i][x]=false;
    }

public:
    bool canCross(vector<int>& stones) {
        // initially we are declaring a vector based on the constraints given
        // in the question and we are initializing it with -1
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        unordered_map<int,int> track;
        // for the map the key is the stone position and the value of the map is
        // is the index of the position of the stone.
        for(int i=0;i<stones.size();i++)
        {
            track[stones[i]]=i;
        }
        // calling for the solve function
        return solve(stones,1,0,dp,track);
    }
};
