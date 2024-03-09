Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Examples: 

Input: arr[] = {1, 2, 3}
Output: A Balanced BST
      2
    /  \
 1     3 
Explanation: all elements less than 2 are on the left side of 2 , and all the elements greater than 2 are on the right side

Input: arr[] = {1, 2, 3, 4}
Output: A Balanced BST
          3
        /  \
     2    4
   /
1


// Approach/Intution to solve the problem

Sorted Array to Balanced BST By Finding The middle element
The idea is to find the middle element of the array and make it the root of the tree, then perform the same operation on the left subarray for the root’s left child and the same operation on the right subarray for the root’s right child.

Follow the steps mentioned below to implement the approach:

Set The middle element of the array as root.
Recursively do the same for the left half and right half.
Get the middle of the left half and make it the left child of the root created in step 1.
Get the middle of the right half and make it the right child of the root created in step 1.
Print the preorder of the tree.


  Problem Statement:

Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Example 1:

Input: nums = {1, 2, 3, 4}
Output: {2, 1, 3, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {2, 1, 3, 4}:
           2
         /   \
           1     3
               \
                4
 

Example 2:

Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
Explanation: 
The preorder traversal of the following
BST formed is {4,2,1,3,6,5,7} :
        4
       / \
      2   6
     / \  / \
    1   3 5  7


  // Code for the above problem statement:

          class Solution {
public:
void solve(vector<int> &nums,int start,int end,vector<int> &ans)
{
    // since it is already mentioned in the question that the array is sorted 
    // so the values < nums[mid] will form left subtree
    // and the values > nums[mid] will form right subtree
    // computing the size of the nums vector
        int n=nums.size();
        //base case
        if(start > end)
        return;
        
        int mid=(start+end)/2;
        ans.push_back(nums[mid]);
        
        // recurrsively call to find the left subtree of the root node
        solve(nums,start,mid-1,ans);
        
        // recurrsively call to find the right subtree of the root node
        
        solve(nums,mid+1,end,ans);
        
}
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        int start=0,end=nums.size()-1;
        
        // calling the solve function to get the pre-order traversal from the sorted array
        
        solve(nums,start,end,ans);
        // finally returning the ans vector which will be having the BST values in pre-order traversal kind of 
        // format
        return ans;
            }
};

Time Complexity:
Space Complexity: Auxillary space of O(n) // since we have used an vector ans which at max i.e worst case will be storing all the elements of the nums 
// vector and this is certain for sure 
Stack Space: O(H) // H is equal to the height of the binary tree that will be formed 
  // since we are supposed to make the BST in height balanced format and then find the pre-order traversal , the number of recursive calls that will be made for
  // the left and right subtree of the root node will be equal to the height of the binary tree that will be formed.
