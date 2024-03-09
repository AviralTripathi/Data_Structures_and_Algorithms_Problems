Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string after performing these r iterations (see examples for better understanding).

Example 1:

Input:
s = "1100"
r = 2
n = 3
Output:
1
Explanation: 
After 1st iteration s becomes "10100101".
After 2nd iteration s becomes "1001100101100110".
Now, we can clearly see that the character at 3rd index is 1, and so the output.
Example 2:

Input:
s = "1010"
r = 1
n = 2
Output:
0
Explanation : 
After 1st iteration s becomes "10011001".
Now, we can clearly see that the character at 2nd index is 0, and so the output.

  Apporach 1:

  class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        string temp = "";
   for (int x = 0; x < r; x++) {
      for (int y = 0; y < s.length(); y++) {
         if (s[y] == '1')
            temp += "10";
         else
            temp += "01";
      }
      s = temp;
      temp = "";
   }
   return s[n];
    
    }
};

Time Complexity: O(L*2^(r)) // L=s.length();
Space Complexity: O(2^r) // in worst case at a given instant of time temp will store this much only.

Approach 2: (more efficiet)

  class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        for (; r > 0; n %= 1 << r--)
        s = s[n / (1 << r)] == '0' ? "01" : "10";
    return s[n];
    }
};

Time Complexity: O(N) // it is just simply the traversal of the string for the no. of times specific (r)
// no extra loop for string and all (means no separate loops for no of itirations & another for string traversal

Space Complexity: O(1) // since we are not using any extra space

