Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.


  Code with comments for the above approach

class Solution {
public:
    int maxVowels(string s, int k) {
        // one pointer a will point to the start of the first index of the very first
        // window
        // and second pointer will pe placed at the index k which will be start of 
        // the second window and so on.
        int a=0,j=k;
        // declaring a count variable to store the number of vowels found in the 
        // susbtring of string s
        int count=0;

        // iterate till k for the first window
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            count++;
        }
        int maxi=count;
        // now since we are suposed to only check the size of sbytring wiuth length k
        // check wherther the count has become =k
        if(count==k)
        // then there can't be any size greater than k
        return count;
        while(j<s.size())
        {
            // firslty while we move on to the next winodw we now to certain elements
            // of the first window and so we are supposed to delete the first element
            // here
            if(s[a]=='a' || s[a]=='e' || s[a]=='i' || s[a]=='o' || s[a]=='u')
            count--;

            a++;

            // if the first charcater of the new substring is a vowel
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            count++;

            // move the j pointer to the next charaacter in the window substrign
            j++;
            maxi=max(count,maxi);

        }
        return maxi;
            }
};


Time Complexity: O(N)
Space Complexity: O(1)
