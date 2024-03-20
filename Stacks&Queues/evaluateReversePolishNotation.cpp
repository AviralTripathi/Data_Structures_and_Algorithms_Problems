You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22


Intuition
The code aims to evaluate an arithmetic expression given in Reverse Polish Notation (RPN). The intuition is to use a stack to keep track of operands and apply the operators when encountered.

Approach
Initialize a stack to store integers.
Iterate through each element in the input array.
If the element is not an operator (+, -, *, /), push the integer representation of the element onto the stack.
If the element is an operator, pop the top two elements from the stack, apply the operator, and push the result back onto the stack.
After iterating through all elements, the final result is at the top of the stack.

  Code:

  class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> expressions({"+","-","*","/"});
        for(const string& element:tokens)
        {
            if(expressions.find(element)==expressions.end())
            st.push(stoi(element));
            else
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(element=="+")
                st.push(num1+num2);
                else if(element=="-")
                st.push(num1-num2);
                else if(element=="*")
                st.push(num1*num2);
                else
                st.push(num1/num2);
            }
        }
        return st.top();
    }
};


Complexity
Time complexity: O(n), where n is the number of elements in the input array.
Space complexity: O(n), as the stack stores integers and the input set of operators.
