Given two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both values exist in the tree. 

Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 
as descendants (where we allow a node to be a descendant of itself). 
The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root [i.e., closest to n1 and n2].

Algo:

Create a recursive function that takes a node and the two values n1 and n2.
If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for the right subtree.
If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for the left subtree.
If both the above cases are false then return the current node as LCA.

Code:

Node* LCA(Node *root, int p, int q)
        {
            if(root==NULL || root->data==p || root->data==q)
        return root;
        Node* leftPart=LCA(root->left,p,q);
        Node* rightPart=LCA(root->right,p,q);
        if(leftPart!=NULL && rightPart!=NULL)
        return root;
        else if(leftPart!=NULL && rightPart==NULL)
        return leftPart;
        else
        return rightPart;
        
        }

Time Complexity: O(H) // H is the height of the tree
Space Complexity: Auxillary Space: O(H) // this is the recrusive stack space  and if this is ignored then there is a constant space complexity
