Follow the below steps to Implement the idea:

Recursively do a Depth-first search.
If the tree is empty then return 0
Otherwise, do the following
Get the max depth of the left subtree recursively  i.e. call maxDepth( tree->left-subtree)
Get the max depth of the right subtree recursively  i.e. call maxDepth( tree->right-subtree)
Get the max of max depths of left and right subtrees and add 1 to it for the current node.
max_depth = max(max dept of left subtree,  max depth of right subtree) + 1  
Return max_depth.


  Time Complexity: O(N) (Please see the post on Tree Traversal for details)
Auxiliary Space: O(N) due to recursive stack.

  // here is the code for the following implementation

   int solve(struct Node* root)
    {
        // declare an integer variable to return the final answer
        int height=0;
        // firstly check for the case of the whether root is pointing to null or not
        if(root==NULL)
        // simply return 
        return 0;
        // compute the height of the left subtree of the root node
        int max_left=solve(root->left);
        // compute the height of the right subtree of the root node
        int max_right=solve(root->right);
        // find the max of these 2 heights and add 1 to it for the root node to get the max depth of the BT
        height=max(max_left,max_right)+1;
        // return height
        return height;
        
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        return solve(node);
    }

// only these 2 functions have been included here rest work of building a tree using level order traversal depenedent on the user and onot on the platform


// next there is another method using the level order traversal

Follow the below steps to Implement the idea:

Traverse the tree in level order traversal starting from root.
Initialize an empty queue Q, a variable depth and push root, then push null into the Q.
Run a while loop till Q is not empty.
Store the front element of Q and Pop out the front element.
If the front of Q is NULL then increment depth by one and if queue is not empty then push NULL into the Q.
Else if the element is not NULL then check for its left and right children and if they are not NULL push them into Q.
Return depth.


// here is the code to implement the same logic

  int height(struct Node* root)
{
 
    // Initialising a variable to count the
    // height of tree
    int depth = 0;
 
    queue<Node*> q;
 
    // Pushing first level element along with NULL
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        // When NULL encountered, increment the value
        if (temp == NULL) {
            depth++;
        }
 
        // If NULL not encountered, keep moving
        if (temp != NULL) {
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
 
        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
    return depth;
}

Time Complexity: O(N)
Auxiliary Space: O(N)

  // another method

  int height(Node* root)
{
 
  // Initialising a variable to count the
  // height of tree
  queue<Node*> q;
  q.push(root);
  int height = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node* temp = q.front();
      q.pop();
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      if (temp->right != NULL) {
        q.push(temp->right);
      }
    }
    height++;
  }
  return height;
}

Time Complexity: O(N)
Auxiliary Space: O(N)

