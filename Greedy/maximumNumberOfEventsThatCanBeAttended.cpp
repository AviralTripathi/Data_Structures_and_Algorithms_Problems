You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 
Example 1:

Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105


Approach
Sort the events based on starting date.

Iterate over all possible days.

Everyday, check if any ongoing event ended, and remove it from pq (ie; mark these events as done).

Add all the events that begin on that day to pq (ie; mark them as ongoing events).

pq now contains ongoing events with pq.top() having the smallest end date. Visit this event.

Continue till there are no ongoing and upcoming events.


  
  Code:

class Solution {
public:
static bool comp(vector<int> &a,vector<int>&b)
{
    return a[0]<b[0];
}
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0;
        int n=events.size();
        int i=0;
        for(int d=1;d<=100000;d++)
        {
            if(i>=n && pq.empty())
            break;
            while(!pq.empty() && pq.top() < d)
            {
                pq.pop();
            }
            while(i<n && events[i][0]==d)
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};

Complexity Analysis:

Time Complexity: 
Space Complexity:
