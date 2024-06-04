Explanation:

Intuition
The problem asks us to find the minimum total cost of making cuts on a wooden stick of length nnn at specific positions given in the cutscutscuts array. We can change the order of the cuts as we wish.
To solve this problem, we can utilize the concept of dynamic programming. The intuition behind the dynamic programming approach is as follows:
We start by sorting the cutscutscuts array in ascending order because the order of cutscutscuts does not affect the final result.

We add 000 at the beginning of the cutscutscuts array and nnn at the end to represent the start and end positions of the stick.

We create a 2D table dpdpdp of size (cuts.size()+1)(cuts.size() + 1)(cuts.size()+1) x (cuts.size()+1)(cuts.size() + 1)(cuts.size()+1). The dp[i][j]dp[i][j]dp[i][j] represents the minimum cost of making cuts in the subinterval from index iii to index jjj of the cuts array.

We iterate over all possible subintervals of the cutscutscuts array. For each subinterval, we consider all possible cutting points within that subinterval.

For each subinterval length lenlenlen from 222 to cuts.size()cuts.size()cuts.size(), we iterate over all starting positions start from 000 to cuts.size()cuts.size()cuts.size() - lenlenlen. We calculate the ending position endendend as start+lenstart + lenstart+len.

For each subinterval, we consider all possible cutting points kkk from start+1start + 1start+1 to end−1end - 1end−1. We calculate the cost of making the cut at position cuts[k]cuts[k]cuts[k] as cuts[end]−cuts[start]cuts[end] - cuts[start]cuts[end]−cuts[start].

We calculate the total cost of making the cuts by adding the cost of the left subinterval (dp[start][k])(dp[start][k])(dp[start][k]) and the cost of the right subinterval (dp[k][end])(dp[k][end])(dp[k][end]). We take the minimum cost among all possible cutting points k within the subinterval.

We update dp[start][end]dp[start][end]dp[start][end] with the minimum cost found for the current subinterval.

Finally, the minimum total cost of making all the cuts is given by dp[0][cuts.size()]dp[0][cuts.size()]dp[0][cuts.size()], which represents the minimum cost of making cuts in the entire stick.

By applying the above dynamic programming approach, we can efficiently compute the minimum total cost of making cuts on the stick.

Approach
To solve the problem, we can use dynamic programming. We'll create a 2D table dp to store the minimum cost of making cuts at various positions.
Here's the step-by-step algorithm:
Sort the cutscutscuts array in ascending order.
Add 000 at the beginning of the cutscutscuts array and nnn at the end to represent the start and end positions.

  nitialize the dpdpdp table with INTINTINT_MAXMAXMAX values of size (cuts.size()+1)(cuts.size() + 1)(cuts.size()+1) x (cuts.size()+1)(cuts.size() + 1)(cuts.size()+1).
For each interval length lenlenlen from 111 to cuts.size()cuts.size()cuts.size():
For each starting index start from 000 to cuts.size()−lencuts.size() - lencuts.size()−len:

Calculate the ending index endendend as start+lenstart + lenstart+len.
Initialize the minimum cost minCostminCostminCost as INTINTINT_MAXMAXMAX.
For each cutting point k from start+1start + 1start+1 to end−1end - 1end−1:
Calculate the cost of making the cut at position cuts[k]cuts[k]cuts[k] as cuts[end]−cuts[start]cuts[end] - cuts[start]cuts[end]−cuts[start].
Calculate the total cost as the sum of the cost of the left subinterval (dp[start][k])(dp[start][k])(dp[start][k]) and the cost of the right subinterval (dp[k][end])(dp[k][end])(dp[k][end]).
Update minCostminCostminCost with the minimum of the current minimum cost and the total cost.
Update dp[start][end]dp[start][end]dp[start][end] with the minimum cost found.
Return dp[0][cuts.size()]dp[0][cuts.size()]dp[0][cuts.size()], which represents the minimum cost of making all the cuts.
Complexity
Time complexity: O(n^3) 

Space complexity: O(n^2)

Code

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        // just above we have created a 2D dp of size m*m;
        // this dp will be storing the minimum cost that incurred by making cuts in
        // an interval of (i,j)
        // since an interval should be minimum of length 2 in order to have cuts 
        // since in question there is no where given about cutting the rod
        // fractionally so least interval length should be 2
        for(int len=2;len<m;len++)
        {
            // this loop is to calculate the number of cuts in the particular
            // sub interval
            for(int start=0;start+len<m;start++)
            {
                int end=start+len;
                int minCost=INT_MAX;
                for(int k=start+1;k<end;k++)
                {
                    int cost=cuts[end]-cuts[start];
                    int totalCost=dp[start][k]+dp[k][end];
                    minCost=min(minCost,totalCost+cost);
                }
                dp[start][end]=minCost;
            }
        }
        return dp[0][m-1];
    }
};
