Problem Statement:

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Code:

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the endWord is not in the dictionary, no valid transformation
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int length = 1;
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return length;
                }
                
                // Remove the current word from the dictionary to prevent revisiting
                // and also preventing the TLE.
                dict.erase(word);
                
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            // Remove word from the dictionary to prevent re-processing
                            dict.erase(word);
                        }
                    }
                    // again substitute the same in word string for further 
                    // evaluations
                    word[j] = originalChar;
                }
            }
            length++;
        }
        
        return 0;
    }
};

// here n is the umber of nodes and length of the each word

Time Complexity: O(N*L)
Space Complexity: O(N*L)
