Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.



Code:

class Solution {
public:
    //Function to check if brackets are balanced or not.
    bool isparHelp(string s)
    {
        stack<char> check;
        for(int i=0;i<s.length();i++)
        {
            char c=s.at(i);
            // if it is an opening brace simply push it 
            if(c=='[' || c=='(' || c=='{')
            {
                //simply put it inside the stack
                check.push(c);
            }
            else if(c==']' || c=='}' || c==')')
            {
                // means know the character will be closing brace
                // firstly get the character present at the top of the stack
                if(check.empty())
                {
                    return false;
                }
                char ch=check.top();
                if((c==']' && ch=='[') || (c=='}' && ch=='{') || (c==')' && ch=='('))
                {
                    //simply pop the element out of stack
                    check.pop();
                }
                
                else
                {
                    // if this condition has not been fulfilled then simply push the element inside the stack
                    check.push(c);
                }
            }
        }
        //upon the complete traversal of the i/p string we will check if the stack is empty or not
        return check.empty();
    }

    bool isValid(string s) {
        return isparHelp(s);
    }
};

Complexity Analysis
