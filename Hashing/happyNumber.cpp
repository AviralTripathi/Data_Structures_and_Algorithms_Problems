Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false


Approach
-> The code uses a while loop to iterate until the number n is reduced to a single-digit number (less than or equal to 9).
-> Inside the loop, it calculates the sum of squares of the digits by iterating over each digit of the current number.
-> The result is stored in the variable ans, and the loop continues until n becomes a single-digit number.
-> The loop then checks if n is equal to 1 or 7. If true, it returns true, indicating that the original number is a happy number.
-> If n is not equal to 1 or 7, the function returns false.

  Code:

class Solution {
public:
    bool isHappy(int n) {
        // we will keep reducing the number till the it turns into a single
        // digit number

        while(n>9)
        {
            int temp=n;
            int ans=0;
            // now we will iterate till the time the number does not become =0
            while(temp)
            {
                // extracting the digit from the number temp
                int digit=temp%10;
                // updating the value of the temp for the next iteration of the 
                // inner loop
                temp=temp/10;
                ans=ans+(digit*digit);
            }
            // update the value of n to ans;
            n=ans;
        }
        // now check for the whether the number on being reduced to the single digit
        // is equal to 1 or 7 if it holds then return true otherwise false
        if(n==1 || n==7)
        return true;
        return false;
    }
};

Time Complexity: The time complexity is approximately O(log n), where n is the input number. It depends on the number of digits in the input.
Space Complexity: The space complexity is O(1) since the code uses a constant amount of extra space, regardless of the input size.
