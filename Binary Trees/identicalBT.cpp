Write a function to determine if two trees are identical or not:

Two trees are identical when they have the same data and the arrangement of data is also the same

Approach: To solve the problem follow the below idea:

To identify if two trees are identical, we need to traverse both trees simultaneously, and while traversing we need to compare data and children of the trees

Follow the given steps to solve the problem:

If both trees are empty then return 1(Base case)
Else If both trees are non-empty
Check data of the root nodes (tree1->data ==  tree2->data)
Check left subtrees recursively
Check right subtrees recursively
If the above three statements are true then return 1
Else return 0 (one is empty and the other is not)


// here is the code for the following problem

bool help(Node* r1,Node* r2)
    {
        // firstly check if the root of both the trees is null then simply return true; they are identical
        if(!r1 && !r2)
        return 1;
        if(r1 && r2)
        {
            // this means that both the trees have something and they are not having null values
            return ((r1->data == r2->data) && help(r1->left,r2->left) && help(r1->right,r2->right));
        }
        // if nothing has been returned uptill now then simply return 0 that means the BTs are not
        // identical
        return 0;
    }
    bool isIdentical(Node *r1, Node *r2)
    {
        return help(r1,r2);
    }

Time Complexity: O(min(m,n)) where m and n are the sizes of the two trees resp.
Space Complexity: O(log(min(m,n))) due to the stack space used by the recursive calls
