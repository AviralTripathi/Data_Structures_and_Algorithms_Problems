Code:
Memoization Solution:

class Solution {
    private:
    int function(string s,vector<string> &wordDict,vector<int> &dp,int start,unordered_set<string> &set)
    {
        if(start==s.size())
        return true;
        // condition for repetitive calls
        if(dp[start]!=-1)
        return dp[start];
        for(int i=start;i<s.size();i++)
        {
            if(set.count(s.substr(start,i+1-start))&& function(s,wordDict,dp,i+1,set))
            {
                dp[start]=true;
                return true;

            }
        }
        return dp[start]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // creating a dp array
        // creating  dp array corresponding to the indexes of the string s
        vector<int> dp(s.size(),-1);
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        return function(s,wordDict,dp,0,set);
    }
};

Time Complexity: O(N^3)
  Space Complexity: O(N)


Code with tabulation method:

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // creating a dp array
        // creating  dp array corresponding to the indexes of the string s
        vector<int> dp(s.size() + 1, 0);
        dp[0] = true;
        // because an empty string(prefix) can always be segmented
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        // the outer loop is to extract the substring characetrs from the input
        // string
        for (int i = 1; i <= s.size(); i++) {
            // the inner loop is to traverse that whole substring which is
            // formed by selecting the ith index from the original string
            for (int j = 0; j < i; j++) {
                // Recursive Step: For each possible prefix of s (s.substr(0,
                // i+1)), check if it exists in the dictionary set. If it does,
                // recursively call wordBreak on the remaining suffix
                // (s.substr(i+1)). If any call returns true, return true.

                if (dp[j] && set.count(s.substr(j, i - j))) {
                    // here this means that this substring can from the space
                    // segmented string
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


Time Complexity: O(N^3)

Space Complexity: O(N)
