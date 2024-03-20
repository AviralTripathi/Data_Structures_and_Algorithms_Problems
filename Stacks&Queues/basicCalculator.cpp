Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.


  class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        // this will take the character one by one sequentially from string
        // while parsing
        int numbers=0;
        // to compute the final result a variable is being used
        int result=0;
        // based upon the value of the element in the string sign value
        // is being assigned which is assigned to positive value since mostly 
        // the first character is a opening bracket
        int sign=1;

        // now will traverse the whole string
        for(int i=0;i<n;i++)
        {
            // using the method of the string library to check whether the given 
            // character is a digit or not
            if(isdigit(s[i]))
            {
                numbers=numbers*10+(s[i]-'0');
            }
            // now the next possibility could be that character is '+'
            else if(s[i]=='+')
            {
                result+=(numbers*sign);
                numbers=0;
                sign=1;
            }
            //next will take the case s[i]='-'
            else if(s[i]=='-')
            {
                result+=(numbers*sign);
                numbers=0;
                sign=-1;
            }
            // now next case for considering the opening bracket
            // which will simply duplicate the sign
            else if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                numbers=0;
                sign=1;
            }
            // now the case of the closing bracket
            else if(s[i]==')')
            {
                result+=(numbers*sign);
                numbers=0;
                int stack_sign=st.top();
                st.pop();
                int last_result=st.top();
                st.pop();
                result*=stack_sign;
                result+=last_result;
            }
        }
        result+=(numbers*sign);
        return result;
    }
};


Complexity Analysis:
