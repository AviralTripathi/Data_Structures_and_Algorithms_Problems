Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

  Approach:

This code implements the longestCommonPrefix function that takes a list of strings v as input and returns the longest common prefix of all the strings. Here is an explanation of how the code works:

Initialize an empty string ans to store the common prefix.
Sort the input list v lexicographically. This step is necessary because the common prefix should be common to all the strings, so we need to find the common prefix of the first and last string in the sorted list.
Iterate through the characters of the first and last string in the sorted list, stopping at the length of the shorter string.
If the current character of the first string is not equal to the current character of the last string, return the common prefix found so far.
Otherwise, append the current character to the ans string.
Return the ans string containing the longest common prefix.
Note that the code assumes that the input list v is non-empty, and that all the strings in v have at least one character. If either of these assumptions is not true, the code may fail.

 Code:

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        // sort the string lexicographically
        sort(v.begin(),v.end());
        int n=v.size();
        // store the first and last elements of the v array in the variable itself
        string first=v[0],last=v[n-1];
        // from i=0 to min of first & last we will iterate
        for(int i=0;i<min(first.length(),last.length());i++)
        {
            // then will be comparing sequencially
            if(first[i]!=last[i])
            // if the characters for prefix don' match then simply return the ans 
            //i.e longest common prefix found so far
            return ans;
            // otherwise simply append the character to the ans variable
            ans+=first[i];
        }
        return ans;
    }
};

Complexity:
