Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Approach
Here's a detailed approach to understand the code:

Approach:
Initialization:

Create a vector count of size 256 (assuming ASCII characters) to keep track of the occurrences of each character in the substring.
Initialize three variables: first, second, and len. first and second are pointers that represent the current substring, while len stores the length of the longest substring encountered so far.
Sliding Window Technique:

Start iterating through the string s using the second pointer.
For each character s[second], check if it has occurred before in the current substring.
Handling Repeated Characters:

If the character at s[second] has already occurred in the current substring:
Move the first pointer until the character is no longer in the substring.
While moving first, update the count vector accordingly to mark that the character is no longer in the substring.
Once the repeated character is removed from the current substring, update the count vector and move to the next character.
Updating Length:

Update the length of the longest substring encountered so far (len) by comparing it with the length of the current substring (second - first + 1).
Move Second Pointer:

Move the second pointer to the next character in the string.
Repeat:

Repeat steps 2-5 until the second pointer reaches the end of the string.
Return Result:

Once the iteration is complete, return the value of len, which represents the length of the longest substring without repeating characters.
This approach effectively utilizes the sliding window technique to find the length of the longest substring without repeating characters in 
linear time complexity O(n), 
  where n is the length of the string s.


  Code:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // declaring an unordered map to keep the track of a charcater being already
        // vsisted once in the current window
        unordered_map<char,int> mp;
        // firstly iterating over the whole string
        for(int i=0;i<s.length();i++)
        {
            // initially for every characater simply a zero is being inserted
            mp[s[i]]=0;
        }

        // now we will following the sliding window approach
        int first=0,second=0,maxLength=0;
        while(second<s.length())
        {
            while(mp[s[second]])
            {
                // that means the value has been already encountered in the current
                // window
                
                // so firstly drop that character from the window as well as from the
                // map mp
                mp[s[first]]=0;
                // increment the frist pointer
                first++;
            }
            // now this is the case for the character being visited for the very
            // first time

            // mark the character in the map as visited
            mp[s[second]]=1;
            //update the len which is computed like: (x,y)=y-x+1
            maxLength=max(maxLength,second-first+1);
            // increment the second pointer to check for the next character in the
            // current window
            second++;
        }
        // simply return the variable maxLength which will be length longest 
        // substring without repeating characters
        return maxLength;
    }
};

Complexity Analysis:

Time complexity:O(N)
Space complexity:O(1)
