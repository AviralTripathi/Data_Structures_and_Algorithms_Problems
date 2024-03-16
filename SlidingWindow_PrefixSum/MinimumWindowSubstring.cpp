Intuition and Approach
The problem asks us to find the minimum window in the string s that contains all the characters from the string t.
Use sliding window approach to efficiently track the minimum window. The sliding window is adjusted based on the characters encountered in the string s, and the frequency of characters from t is maintained using a map.

Initialization:
-- If the length of string t is greater than the length of string s, it is impossible to find a valid window, so return an empty string.

-- Initialize variables iii and jjj to represent the window's start and end, and headheadhead to keep track of the starting index of the minimum window.

-- Create a map mpmpmp to store the frequency of characters in string t.

Sliding Window:
-- Iterate through the characters of string s using pointers i and j. For each character s[j]:

2.1 If it is a character from t (found in the map mpmpmp):
-- Decrease its count in the map.
-- If its count becomes zero, decrement the countercountercounter (the number of distinct characters from t that are still needed).
-- Move the right pointer j to the next character.
-- If counter becomes zerozerozero, it means all characters from t are found in the current window. Proceed to the next step.

Shrinking Window
-- While counter is zero (indicating all characters from t are present), try to minimize the window by moving the left pointer i.
Update the minimum window size and starting index (headheadhead) if the current window is smaller.

-- If the character at s[i] is from t, increase its countcountcount in the map.

-- If its count becomes positive, increment the counter (indicating that we need this character in the window). Move the left pointer i to the next character.

Result:
-- Repeat the process until the end of the string s.
-- The final resultresultresult is the minimum window substring in string s that contains all characters from string t, or an empty string if no such window exists.

Complexity
Time complexity: O(N+M)
Space complexity: O(N)
