You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Approach:

Intuition
My initial thought to solve this problem is to iterate through the list of intervals and compare each interval with the new interval to determine its position for insertion.

Approach
I will traverse through the list of intervals and compare each interval's start and end points with the start and end points of the new interval. Based on the comparison, I will insert the new interval appropriately, ensuring that the resulting list remains sorted and non-overlapping.


Code:
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        bool inserted=false;
        int start=newInterval[0];int end=newInterval[1];
        for(int i=0;i<intervals.size();i++)
        {
            int cstart=intervals[i][0];
            int cend=intervals[i][1];

            if(cend<start || inserted)
            {
                ans.push_back({cstart,cend});
                continue;
            }
            start=min(start,cstart);
            if(end<cstart)
            {
                // push the new interval here
                ans.push_back({start,end});
                ans.push_back({cstart,cend});
                inserted=true;
                continue;
            }
            if(end<=cend)
            {
                ans.push_back({start,cend});
                inserted=true;
            }
        }
        if(!inserted)
        {
            // this means that simply insert the interval at the last
            ans.push_back({start,end});
        }
        return ans;
    }
};
  
Complexity
Time complexity: O(n), where n is the number of intervals in the input list. This is because we iterate through the list of intervals only once.

Space complexity: O(n) as well. We are using extra space to store the resultant list of intervals, which could potentially contain all intervals from the input list plus the new interval.
