Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.


Explanation of the code:

Intuition
One way to approach this problem is to use a greedy strategy. We can keep track of the minimum and maximum number of open parentheses that must be matched and see if it's possible to match all the parentheses in the string. We'll use two variables leftMin and leftMax to represent the minimum and maximum number of open parentheses respectively.
Approach
1. Initialize leftMin and leftMax to 0.
2. Iterate through each character in the string s.
3. If the character is '(', increment both leftMin and leftMax by 1.
4. If the character is ')', decrement both leftMin and leftMax by 1.
5. If the character is '*', decrement leftMin by 1 and increment leftMax by 1.
6. If leftMax becomes negative at any point, return False since it means there are more closing parentheses than opening ones.
7. If leftMin becomes negative, reset it to 0 since we can't have negative open parentheses count.
8. After iterating through the string, check if leftMin is 0. If it is, return True; otherwise, return False.
Time complexity:
O(n), where n is the length of the input string s. We iterate through the string once.
Space complexity:
O(1), as we only use a constant amount of extra space for variables.

  Code:

  class Solution {
public:
    bool checkValidString(string s) {
        int leftMin=0,leftMax=0;
        for(char c:s)
        {
            if(c=='(')
            {
                leftMin++;
                leftMax++;
            }
            else if(c==')')
            {
                leftMin--;
                leftMax++;
            }
            else
            {
                leftMin--;
                leftMax++;
            }
            if(leftMax < 0)
            return false;
            if(leftMin < 0) leftMin=0;
        }
        return leftMin==0;
    }
};
