You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105


Code:

  class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        return NULL;
        int count=0;
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        int i=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(i<((count+1)/2))
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        // pointing the previous node before the middle node to the node next to
        // the middle node
        prev->next=curr->next;
        // curr->next=NULL;
        
        // deleting the middle node
        delete curr;
        // return the head of the modified list
        return head;
    }
};
  

Approach:

This code defines a function deleteMiddle to remove the middle node of a singly-linked list.

It checks if the list is empty or has only one node, in which case it returns NULL.
It traverses the list to count the number of nodes.
It initializes pointers prev and curr to traverse the list again.
It moves curr to the middle node and prev to its previous node.
It updates prev->next to skip the middle node, effectively removing it from the list.
It deletes the middle node to free memory.
It returns the head of the modified list.
The function operates in O(n) time complexity, where n is the number of nodes in the list.
It does not handle cases where the list has an even number of nodes.
It assumes the input list is valid and does not handle edge cases like invalid input pointers.

  
Complexity
Time complexity:O(n)
Space complexity:O(1)
