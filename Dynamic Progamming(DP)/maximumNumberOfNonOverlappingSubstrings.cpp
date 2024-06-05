Approach:

let's start with the base case:-
Simply if we go out of bound we need to return 0,easy right?..
if we have value stored in dp return that value.i.e.
if(dp[i]!=-1)
return dp[i];
Next we have temp that will store the substring if we include a particular character and similarly we have answer that we need to maximize.
Now we run a for loop from the current index to size of string and adding the character to temp.
If size of temp>=k and temp is a palindrome i.e.basically if both conditions mentioned in question are satisfied,then we have an option of include it.So,i sent a recursive call for next index i.e. (j+1) and +1 in find for inclusion and taking the maximum between calculated value and ans as discussed earlier.
Unlike inclusion,exclusion is condition independent i.e. we can always have a choice of exclusion.So,in the very next line i have calculated the maximum of ans and excluded value.
And finally stored the value in dp table and returned the answer.

  Code:


class Solution {
    private:
    bool ispalindrome(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return 0;
            i++,j--;
        }
        return 1;
    }
    int check(string &s,int k,int i,vector<int> &dp)
    {
        if(i>=s.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        string temp="";
        int ans=0;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(temp.size()>=k && ispalindrome(temp))
            // to check for another substring after j index that is j+1
            ans=max(ans,1+check(s,k,j+1,dp));
            // this is the condition for the exculsion 
            ans=max(ans,check(s,k,j+1,dp));
        }
        return dp[i]=ans;
    }
public:
    int maxPalindromes(string s, int k) {
        // we are declaring here a 1-d dp since there is only one varying parameter
        // that is index to traverse the whole string.
        vector<int> dp(s.size()+1,-1);
        return check(s,k,0,dp);
    }
};


// Time Complexity: O(n^2)
// Space Complexity: O(n^2)


// this code will give TLE though all the test cases will be passed


Code: optimized solution using tabular dp

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // Precompute the palindrome substrings
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    isPalindrome[i][j] = true;
                } else if (len == 2) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] =
                        (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
            }
        }

        // DP array to store the maximum number of non-overlapping palindromes
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            for (int j = i; j < n; ++j) {
                if (isPalindrome[i][j] && j - i + 1 >= k) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};

// Time Complexity: O(n^2)
// space complexity: O(n^2)

// Initially, we assume that if we do not consider any palindromic substring
// starting at index i, the maximum number of non-overlapping palindromic
// substrings we can find from index i onward is the same as the maximum number
// we can find from index i + 1 onward. In other words, we are carrying forward
// the value from the next position (i + 1) to the current position (i).
