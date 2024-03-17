Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Code:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       // firstly declare an answer vector ans
        vector<vector<int>> ans;
        // firstly check whether the given vector is empty or not
        if(intervals.size()==0)
        return ans;
        
        // next step is to sort the list 
        sort(intervals.begin(),intervals.end());
        
        //define a stack for the problem
        stack<vector<int>> overlap;
        
        // firstly push the first interval inside the stack
        overlap.push(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> current=intervals[i];
            //imp line
            vector<int> &top=overlap.top();
            
            // here comes the condition for checking of overlap
            if(current[0] <=top[1])
            {
                top[1]=max(top[1],current[1]);
            }
            else
            {
                // simply push the interval inside the stack
                overlap.push(intervals[i]);
            }
        }
        
        // now the stack has the given vector devoid of all the overlapping intervals
        
        while(!overlap.empty())
        {
            ans.push_back(overlap.top());
            overlap.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        // finally return the answer vector
        return ans; 
    }
};
