Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Intuition
The intuition behind the solution is to iterate through the given string and keep track of the length of the last word encountered. By considering spaces as separators between words, 
we can determine the length of the last word by counting the characters until the next space or the end of the string.

Approach
-> Initialize a count variable to 0. This variable will keep track of the length of the last word.
-> Create a boolean variable called space and set it to false. This variable will help identify when a space character is encountered.
-> Iterate through each character of the string using a for loop.
-> Check if the current character is a space character by comparing it to ' '. If it is, set the space variable to true.
-> If the current character is not a space character and the space variable is true, it means we have encountered the first character of a new word. In this case, set the count to 1 and reset the space variable to false.
-> If the current character is not a space character and the space variable is false, it means we are still in the middle of a word. In this case, increment the count by 1.
-> After iterating through all the characters, the count will hold the length of the last word in the string.
-> Return the count as the result.

Code:

class Solution {
public:
    int lengthOfLastWord(string s) {
        // Variable to store the length of the last word
        int count=0;
        // Boolean variable to track if a space is encountered
        bool space=false;
        // Iterate through each character in the string
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            // If a space character is encountered
            space=true;
            else if(s[i]!=' ' && space)
            // If a non-space character is encountered after a space
            {
                // that means we are at the first character of the new word
                // Start counting a new word
                count=1;
                space=false;
            }
            else
            // this means that we are in the middle of the word so keep incrementing
            // the count variable
            // Increment the count for non-space characters
            count++;
        }
        // finally return the count variable which will be holding the length of
        // the last word of the string
        return count;
    }
};
  
Complexity
Time complexity:
The time complexity of this approach is O(n)O(n)O(n), where n is the length of the input string. We iterate through the string once to determine the length of the last word.

Space complexity:
The space complexity of this approach is O(1)O(1)O(1) since we are using a constant amount of additional space to store the count and the space flag, regardless of the size of the input string.
