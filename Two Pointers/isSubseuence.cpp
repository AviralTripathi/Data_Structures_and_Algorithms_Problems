Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


class Solution {
public:
    bool isSubsequence(string s, string t) {
        // firstly compute the size of both the strings
        int i=s.size();
        int j=t.size();
        // initializing two pointer to traverse both the strings
        int first=0,second=0;
        // we will be traversing till the end of the string t
        while(second<j)
        {
            if(s[first]==t[second])
            // if we find a match character then simply move both the pointers
            // ahead
            first++,second++;
            else
            // then for checking the particular character of we will move the 
            // pointer of t 
            second++;
        }
        // now will be checking that whther because of successful matching of 
        // characters has first pointers reached the length of the string that 
        // it was traversing 
        if(first==i)
        // that means all the characters have been matched
        // simply return true
        return true;
        else
        // simply return false;
        return false;
    }
};
