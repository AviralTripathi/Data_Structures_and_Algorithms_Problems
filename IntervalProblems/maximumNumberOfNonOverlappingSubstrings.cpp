Problem Statement:  Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

 

Example 1:

Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

Explaination:

Initialization:

int n = s.size();
vector<int> first(26, -1), last(26, -1);
n stores the length of the input string s.
first and last are vectors of size 26 (to cover all lowercase English letters). These vectors will store the first and last occurrence indices of each character in the string.
Finding First and Last Occurrences:

for (int i = 0; i < n; ++i) {
    if (first[s[i] - 'a'] == -1) {
        first[s[i] - 'a'] = i;
    }
    last[s[i] - 'a'] = i;
}
This loop iterates through the string s.
first[s[i] - 'a'] sets the first occurrence index of the character s[i] if it hasn't been set before (-1 indicates it hasn't been set).
last[s[i] - 'a'] updates the last occurrence index of the character s[i] to the current index i.
Creating Intervals:

vector<pair<int, int>> intervals;

for (int i = 0; i < 26; ++i) {
    if (first[i] != -1) {
        int l = first[i], r = last[i];
        bool valid = true;
        for (int j = l; j <= r; ++j) {
            if (first[s[j] - 'a'] < l) {
                valid = false;
                break;
            }
            r = max(r, last[s[j] - 'a']);
        }
        if (valid) {
            intervals.push_back({l, r});
        }
    }
}
Iterate over each character (from a to z).
If a character has been seen in the string (i.e., first[i] != -1), create an interval [l, r] where l is the first occurrence and r is the last occurrence of the character.
For each character in the interval [l, r], check if its first occurrence is within the interval. If not, mark the interval as invalid.
Adjust the right boundary r to include the last occurrence of all characters within the interval.
If the interval is valid (i.e., contains all occurrences of all characters in it), add it to the intervals vector.
Sorting Intervals by Their End Positions:

sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
});
Sort the intervals by their end positions (r). This sorting helps in selecting the maximum number of non-overlapping intervals using a greedy approach.
Finding Non-Overlapping Intervals:

vector<string> result;
int end = -1;

for (auto& interval : intervals) {
    if (interval.first > end) {
        result.push_back(s.substr(interval.first, interval.second - interval.first + 1));
        end = interval.second;
    }
}
Initialize an empty result vector to store the substrings.
Initialize end to -1 to track the end of the last added interval.
Iterate through the sorted intervals:
If the start of the current interval is greater than the end of the last interval, it means this interval does not overlap with the previously selected intervals.
Add the substring corresponding to the current interval to the result.
Update end to the end of the current interval.
Return the Result:

return result;
Return the result vector containing the maximum number of non-overlapping substrings that meet the conditions.





Code:

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Find first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        // Create intervals for each character
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1) {
                int l = first[i], r = last[i];
                bool valid = true;
                for (int j = l; j <= r; ++j) {
                    if (first[s[j] - 'a'] < l) {
                        valid = false;
                        break;
                    }
                    r = max(r, last[s[j] - 'a']);
                }
                if (valid) {
                    intervals.push_back({l, r});
                }
            }
        }

        // Sort intervals by their end position
      // greedy appraoch to get the maximum number of substrings
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int end = -1;

        // Find non-overlapping intervals
        for (auto& interval : intervals) {
            if (interval.first > end) {
                result.push_back(s.substr(
                    interval.first, interval.second - interval.first + 1));
                end = interval.second;
            }
        }

        return result;
    }
};

Time Complexity: O(n) n: length of the input string

Space Complexity: O(n) n: length of the input string
