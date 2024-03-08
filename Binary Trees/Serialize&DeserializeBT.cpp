Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across 
a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization 
  algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, 
  so please be creative and come up with different approaches yourself.

  // Sample Input and Ouptut:

//   Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []


  // Code

  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Explanation for the process of the serialize is that firstly since we are working on a tree so we have to check for whether the root is null or not and for 
/*and for that reason only we have firstly check for the root and if the root is null then alongwith a comma ',' we also have passed '#' which 
indicates the NULL of the BT so now we will simply converting the node values to string using the in-built function and to mark the end of the 
traversal of the level the formatted strings have been concatenated in between by the comma and the resultant value has been returned reecusrively*/

/*Now comes the task of deserialize has been done using the queue and stringstream thing. This has been done to simply ensure the a partcular string that 
has been passed to the queue will be all the node's value that belong to a particular level will separte it ans will further pass to the further function 
calls as a token (i.e value is being held or processed individually)  and getline has been used since for the comma to encounter for the spaces
and then it is passed to deserializeHelper function which simply the string elements in the 
queue of a partcular level and converts all the values in the queue to integer using stoi function. Now stoi() can give run-time error due to handling of the null 
values which has been handled by try catch of the exception handling
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if (!root) return "#,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string nodeValue;
        while (getline(ss, nodeValue, ','))
            q.push(nodeValue);
        return deserializeHelper(q);
    }
    TreeNode* deserializeHelper(queue<string> &q)
    {
        if (q.empty())
        return NULL;
    
    string s = q.front();
    q.pop();
    
    if (s == "NULL")
        return NULL;
    
    int val;
    try {
        val = stoi(s);
    } catch (const std::invalid_argument& e) {
        // Handle invalid conversion
        return NULL;
    }
    
    TreeNode* root = new TreeNode(val);
    root->left = deserializeHelper(q);
    root->right = deserializeHelper(q);
    return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

Time Complexity:
Space Complexity:
