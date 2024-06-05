Approach:

Actually, this problem is to find the maximum sum of increasing subsequence.
Very similiar with 300.Longest Increasing Subsequence

This problem want both age and score are increasing.
We can sort by age and do DP for scores.
Sum up, 3 key points:

Create another arr by {age[i], socres[i]} and sorted by age.
For each loop, goes back and find maximum for current DP value to it maintain a increasing subsequence.
The answer could in any place of the dp array.
Time complexity: O(n * n), space complexity: O(n)



Code:

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        // dp is an array where dp[i] will store the maximum team score that can
        // be achieved by including the player at index i.

        vector<int> dp(n, 0);
        // first parameter of pair is age
        // second parameter is: scores
        vector<pair<int, int>> arr(n, {0, 0});
        for (int i = 0; i < n; i++) {
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }
        // sort the arr vector based upon the ages of players and for that we
        // can use simply arr.begin() & arr.end() ;
        sort(arr.begin(), arr.end());
        int teamScore = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i].second;
            for (int j = i - 1; j >= 0; j--) {
                // arr sorted by age, latter element has to have high score to
                // maintain increasing susequence

                if (arr[i].second >= arr[j].second)
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
            }
            teamScore = max(dp[i], teamScore);
        }
        return teamScore;
    }
};
