There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].


Appraoch:

Simply sorting the intervals and checking if there any intersection between the current 2 intervals as we move along the array. If there is any intersection we use that or else we store next interval for further use.

Code:

  class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        vector<int> curr=points[0];
        int ans=1;
        for(int i=0;i<n;i++)
        {
            // checking if the interval is different
            if(points[i][0]!=curr[0] || points[i][1]!=curr[1])
            {
                // checking if there is some intersection in the interval
                if((points[i][0]>=curr[0] && points[i][0]<=curr[1]) || (points[i][1]<=curr[1] && points[i][1]>=curr[0]))
                {
                    curr[0]=max(points[i][0],curr[0]);
                    curr[1]=min(points[i][1],curr[1]);
                }
                else
                {
                    curr=points[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};
  
Complexity
Time complexity:
O(nlogn)

Space complexity:
O(1)
