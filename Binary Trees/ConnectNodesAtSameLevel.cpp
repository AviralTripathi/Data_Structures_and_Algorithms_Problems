Given a Binary Tree, The task is to connect all the adjacent nodes at the same level starting from the left-most node of that level, 
and ending at the right-most node using nextRight pointer by setting these pointers to point the next right for each node. 

Input:

         1
       / \
     2   3
    / \    \
  4   5   6

Output:

         1—>NULL
       /  \
     2–>3–>NULL
   /   \      \
 4–>5–>6–>NULL


  Algo:

// Follow the below steps to Implement the idea:

// Initialize a node pointer Prev to NULL and a queue of node pointer Q.
// Traverse the tree in Breadth-first search order starting from the root.
// Calculate the size sz of the Q and run a for loop from 0 to sz – 1.
// If prev is Null then set prev to the current node.
// Else set prev’s next to the current node and prev to the current node.
// Set prev’s next to Null and prev to Null.
// If the current node’s left is not null push it into the queue.  
// If the current node’s right is not null push it into the queue.


// here is the implementation of the above code

void connect(Node *root)
    {
       // Base Condition
       if(root==NULL)
       return;
       // declaring a queue for the level order traversal that is simple BFS
       queue<Node*>q;
       q.push(root);
       while(!q.empty())
       {
           int size=q.size();
           Node* prev=NULL;
           while(size--)
           {
               Node* temp=q.front();
               q.pop();
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               q.push(temp->right);
               if(prev!=NULL)
               prev->nextRight=temp;
               prev=temp;
           }
           prev->nextRight=NULL;
       }
    }

Time Complexity: O(N)  // no of nodes in the trees
Space Complexity: auxillary space O(N)
