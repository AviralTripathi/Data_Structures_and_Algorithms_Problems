Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


class Solution {
public:
    int strStr(string s1, string s2) {
        // we will be using the sliding window approach
    int i = 0, j = 0;
    // this string will be storing the string temporairly and will help in comparison
    string p = "";
    for (int j = 0; j < s1.length(); j++)
    {
        p.push_back(s1[j]);
        // now for the case when the length of the window becomes more than the length
        // of the s2 string
        if (p.length() > s2.length())
        {
            // we will shrink the window
            // firstly we will reverse the string and then delete the last(first)
            // character and then we will reverse then string again
            reverse(p.begin(),p.end());
            p.pop_back();
            reverse(p.begin(),p.end());
            // also will increment the i pointer;
            i=i+1;
        }
        if ((p.length() == s2.length()) && (s2.compare(p) == 0))
        {
            // here will be returning the first index of that window
            // first occurence of the word if found will be given by i;
            return i;
        }
    }
    // this is if uptill now the word has not been found.
    return -1;
    }
};

Time Complexity:
Space Complexity:
