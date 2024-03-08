Given a binary search tree and a key(node) value, find the floor and ceil value for that particular key value.

Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
Ceil Value Node: Node with the smallest data larger than or equal to the key value.

  Example:

           8
        /   \    
     4      12
   /  \    /  \
2    6  10   14

Key: 11  Floor: 10  Ceil: 12
Key: 1   Floor: -1  Ceil: 2
Key: 6   Floor: 6   Ceil: 6
Key: 15  Floor: 14  Ceil: -1


  Ceil in Binary Search Tree using Recursion:
To solve the problem follow the below idea:

Imagine we are moving down the tree, and assume we are root node. 
The comparison yields three possibilities,

A) Root data is equal to key. We are done, root data is ceil value.

B) Root data < key value, certainly the ceil value can’t be in left subtree. 
     Proceed to search on right subtree as reduced problem instance.

C) Root data > key value, the ceil value may be in left subtree. 
     We may find a node with is larger data than key value in left subtree, 
     if not the root itself will be ceil node.


  Code Implementation:

int findCeil(Node* root, int input) {
    // Base Case
    if(root==NULL)
    return -1;
    
    // if key's value == root->data
    if(root->data==input)
    return root->data;
    
    // if root's key is smaller than the input then ceil value will be in the right subtree
    if(root->data < input)
    return findCeil(root->right,input);
    
    // else ceil value is either in left subtree or root has the ceil value
     int ceil=findCeil(root->left,input);
     return (ceil >= input)?ceil:root->data;
}

Time Complexity: O(logN)
Space Complexity: O(logN) // Auxillary Space
