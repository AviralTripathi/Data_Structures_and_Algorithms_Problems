Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.


Intuition
The given solution uses a stack to keep track of the directories in the given path. The input string path is iterated over character by character, and whenever a directory name is encountered (i.e., a sequence of characters between two / characters), it is added to the stack. If . is encountered, it is skipped as it represents the current directory. If .. is encountered, the top element of the stack is removed as .. represents the parent directory.

Once the iteration is complete, the elements in the stack are concatenated into a string starting from the top of the stack, separated by /. This gives us the simplified path.

If there are no directory names in the given path, then the root directory / is returned as the simplified path.

Approach
Here's a step-by-step approach of the code you have written above:

Initialize a stack variable st to hold the names of directories in the given path and a string variable ans to hold the simplified path.

Iterate over each character in the input string path using a loop, starting from the first character.

If the current character is a /, skip it as it is not part of a directory name.

Otherwise, initialize an empty string variable temp.

Keep iterating over the characters in path until either a / is encountered or the end of the string is reached.

Append each non-/ character encountered to temp.

If temp is equal to ., skip it as it represents the current directory.

If temp is equal to .., then check if there are any elements in the stack. If the stack is not empty, remove the top element from the stack as it represents the parent directory.

Otherwise, push temp onto the stack as it represents a valid directory name.

Once the iteration is complete, iterate over the elements in the stack using another loop.

For each element, add a / character followed by the element itself to the beginning of ans.

Remove the top element from the stack.

Once all elements in the stack have been added to the beginning of ans, check if ans contains any elements.

If ans contains elements, return it as the simplified path.

Otherwise, return / as the simplified path, as there were no directories in the input path.


Code:

class Solution {
public:
    string simplifyPath(string path) {
        int len=path.length();
        stack<string> st;
        string ans="";

        // will iterate over the given input string path
        for(int i=0;i<len;i++)
        {
            if(path[i]=='/')
            continue;
            string temp="";
            while(i<len && path[i]!='/)
            temp+=path[i++];
            if(temp==".")
            continue;
            if(temp=="..")
            {
                if(!st.empty())
                st.pop();
                continue;
            }
            st.push(temp);
        }
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.size())
        return ans;
        else
        return "/";
    }
};

Complexity:

Time Complexity: O(N+M)
Space Complexity: O(N)
