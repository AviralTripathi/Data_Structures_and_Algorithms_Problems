There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

Approach
Calculate altitude at all levels and take the maximum of all of these altitudes.
Initialise 2 variables, maxm (this represents the maximum height upto the current level) and sum (this represents the altitude at the current level).
Iterate through the gain vector, and add the gain at the current level to the sum variable.
Update maxm as the maximum of maxm and sum, since maxm is the maximum height of all the level before the current level, and sum is the height at the current level. If sum is greater than maxm, then the output upto the current level should be sum, else it should be maxm.


Code:

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int ans=0;
        for(int i=0;i<gain.size();i++)
        {
            sum+=gain[i];
            ans=max(ans,sum);
        }
        return ans;

    }
};

Time Complexity: O(n)
Space Complexity: O(n)
