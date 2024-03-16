You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
There is no substring of length 16 in s that is equal to the concatenation of any permutation of words.
We return an empty array.
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.


Explanation of the approach:

checkSubstring Function:

This function checks if a given substring of string s can be formed by concatenating words from the wordCount dictionary.
It iterates through the string s in steps of the length of a word (wordLen).
For each iteration, it extracts a substring w of length wordLen.
It checks if w exists in the wordCount dictionary. If it does, it increments the count of w in a local seen map and compares it with the count in wordCount. If the count in seen exceeds the count in wordCount, it returns false. If w doesn't exist in wordCount, it returns false.
If all substrings can be formed from the words in wordCount without exceeding their count, it returns true.

  
findSubstring Function:

This function aims to find all starting indices of substrings in string s where each substring is a concatenation of all words in the words vector.
It initializes an empty vector res to store the indices of found substrings.
It calculates wordLen as the length of the first word in words, sLen as the length of string s, and wordsWindow as the total window size required for checking substrings.
It constructs an unordered map wordCount to store the frequency of each word in words.
It iterates through string s with a window size of wordsWindow. Within each iteration, it calls checkSubstring with the current window of s. If checkSubstring returns true, it means a substring composed of words in words is found at the current index, so it adds the index to the res vector.
Finally, it returns the res vector containing the starting indices of all found substrings.


Code:

class Solution {
public:
    bool helper(string s, int word, unordered_map<string, int> mp) {
        for (int i = 0; i < s.size(); i += word) {
            string a = s.substr(i, word);
            if (mp.find(a) != mp.end()) {
                if (--mp[a] < 0)
                    return false;
            } else
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        int word = words[0].size();
        int len = words.size() * word;
        unordered_map<string, int> mp;
        for (auto it : words) {
            mp[it]++;
        }
        int a = 0;
        while (a + len <= s.size()) {
            if (helper(s.substr(a, len), word, mp))
                v.push_back(a);
            a++;
        }
        return v;
    }
};


Complexity:

Time Complexity:
Let:

n be the length of string s.
m be the length of each word in the words vector.
k be the number of words in the words vector.
Constructing wordCount takes O(k) time.

Iterating through each substring of length wordsWindow in s takes O(n) time.

For each substring, checking if it can be formed from words in wordCount takes O(m) time.

Overall, the time complexity is O(n * m).

Space Complexity:
The space complexity mainly depends on the wordCount and seen maps.
wordCount map stores at most k entries, so it takes O(k) space.
seen map is constructed for each substring, and at most it can have k distinct words, so it also takes O(k) space for each substring.
Thus, the overall space complexity is O(k).
