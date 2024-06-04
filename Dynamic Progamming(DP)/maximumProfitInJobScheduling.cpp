Problem Statement:

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:

  Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.


Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104


  Intuition
Sort the arry and use Binary Search and ,Use the Concept of Pick and Non Pick Dynamic approach to solve the question.

Approach
Make a another 2D arry ehich stire all start time ,end time and profit.
sort the arry by starting time.
write a solve function which is used to calaulate maxum profit dp function,pass sorted array and start by '0' index.
Write a Binary Search function to get the next colosest start time to the current picked end time.
Write a Binary Search Function and return the closet indxt start time to the current end time .
The solution Will Get Time Limit Exeeded ,Memoiize the solution.
Take Memo arry of size 50001,and inatilize with -1;
In The solve Function Only Chaning Variable is idx, so store the solution of the subproblems .
if already solved solutio just return the solved solution.
Complexity
Time complexity:
O(n)
Space complexity:
O(n)

Code:

class Solution {
    private:
    int findNextIndex(vector<vector<int>> &arr,int l,int target)
    {
        // r is initialized to the last index of the start time;
        int r=arr.size()-1;
        // ans is initialized to n+1 to point out infinite index initially
        int ans=arr.size()+1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=target)
            {
                // this means the start time of the next activity if it is 
                // exact or after the end time of the previous activity then 
                // it's good
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
    int solve(vector<vector<int>> &arr,int index,vector<int> &dp)
    {
        if(index>=arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int next=findNextIndex(arr,index+1,arr[index][1]);
        int taken=arr[index][2]+solve(arr,next,dp);
        int notTaken=solve(arr,index+1,dp);
        return dp[index]=max(taken,notTaken);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }
        // sort the array based upon the start time
        sort(arr.begin(),arr.end());
        // declaring a 1-d dp array
        vector<int> dp(50001,-1);
        return solve(arr,0,dp);
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
