Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Code:

class BSTIterator {
public:
stack<TreeNode*> st;
TreeNode* curr;
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    
    int next() {
        while(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();st.pop();
        int val=curr->val;
        curr=curr->right;
        return val;
    }
    
    bool hasNext() {
     return curr || (!st.empty());   
    }
};


Explaination of the following above code:

Class Definition:

class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* curr;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
Here, a class BSTIterator is defined, which is used to iterate through a binary search tree (BST). It has two member variables:

stack<TreeNode*> st: This stack is used to keep track of the nodes that need to be visited during iteration.
TreeNode* curr: This pointer is used to keep track of the current node being visited during iteration. Initially, it's set to the root of the BST.
The constructor BSTIterator(TreeNode* root) initializes the curr pointer with the root of the BST passed as an argument.

Next Function:
int next() {
    while(curr) {
        st.push(curr);
        curr = curr->left;
    }
    curr = st.top();
    st.pop();
    int val = curr->val;
    curr = curr->right;
    return val;
}

The next() function is used to retrieve the next element in the BST in ascending order. It follows an in-order traversal approach. Here's how it works:

It traverses down the left subtree of the current node until it reaches a leaf node, pushing all encountered nodes onto the stack (st).
Once it reaches a leaf node, it pops the top node from the stack, retrieves its value, and sets curr to the right child of the popped node to explore its right subtree in the next call.
Finally, it returns the value of the popped node.
HasNext Function:


bool hasNext() {
    return curr || (!st.empty());   
}

The hasNext() function checks whether there are more elements to iterate over in the BST. It returns true if either of the following conditions is true:

curr is not NULL, indicating that there are more nodes to explore in the current subtree.
The stack st is not empty, indicating that there are more nodes to be visited in the BST.
Overall, this BSTIterator class provides an efficient way to iterate over a BST in ascending order using the next() function, and it allows checking if there are more elements to iterate using the hasNext() function.



Complexity Analysis:
