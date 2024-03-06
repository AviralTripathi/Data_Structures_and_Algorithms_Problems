A height balanced binary tree is a binary tree in which the height of the left 
subtree and right subtree of any node does not differ by more than 1 and both the left and right subtree are also height balanced.

Get the height of left and right subtrees using dfs traversal. Return true if the 
difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false. 

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    // to check for the height balanced we need to compute for the height balanced
    int height(Node* root)
    {
        // firstly it needs to be checked that whether the root is null or not
        if(root==NULL)
        // no need to compute the height and simply return 0
        return 0;
        
        return 1+max((height(root->left)),height(root->right));
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // a tree is balanced if the difference in the height of the left and right subtree is <=1
        // alongwith the left and right subtree being balanced as well
        
        // before proceeding with anything we firstly need to check whether the root is null or not
        if(root==NULL)
        return 1;
        int left=height(root->left);
        int right=height(root->right);
        
        // now checking for the condition
        if(abs(left-right) <=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
        // else if the condtion has not been fulfilled that means the tree is not height balanced
        return 0;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends


Time Complexity: O(n^2) in case of a full binary tree
Space Complexity: O(N) space for call stack since using recursion
