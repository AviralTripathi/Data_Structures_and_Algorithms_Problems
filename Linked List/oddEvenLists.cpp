Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106


Intuition
Using Three pointer approach.

Approach
Step 1. Initialize head node as the start of odd pointer & initialize haed->next as the start of even pointer.(using these pointer we will iterate over link list).
Since head is pointing at odd pointer which denotes the start of odd index link list, we need one more pointer to denote the start of even index link list (head2).

Step 2. we know that even pointer will adhead of odd pointer, so we can make the while loop terminate using even pointer.

Step 3. In Loop, we are going change how each node is pointing to each other.
A. First (1st node)O->next = (3rd node)O->next->next, which means 1st node is connected to 3rd node now.
B. then we Do O = O->next which means O now points to 3rd node in link list, since we connected the 1st node to 3rd node in previous step.
C. Now for Even Pointer, (2nd node)E->next = (4th node)E->next->next, which means 2nd node is connected to 4th node now.
D. then we Do E = E->next which means E now points to 4th node in link list, since we connected the 2nd node to 4th node in previous step.

Loop will continue in simalar fashon until the Even pointer is pointing to Null or last Node, since we know Odd pointer will always be one step behind even pointer.

Step 4. We will join both even & odd indexed link list by making the last node of odd indexed link list point to the start of even indexed link list (O->next = head2) .


Code:

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* o=head,*e=head->next,*head2=e;
        // since the e pointer will always reamin of the odd pointer so
        // therefore we will terminate the while loop using even pointer
        while(e!=NULL && e->next!=NULL)
        {
            // pointing 1 th node to the 3rd node and so on
            o->next=o->next->next;
            // now o itself is the odd pointer
            o=o->next;
            // pointing 2nd node to the 4th node and so on
            e->next=e->next->next;
            // now e itself is the 4th node
            e=e->next;
        }
        // pointing the last node of the odd list to the head of the even list
        o->next=head2;
        return head;
    }
};

Complexity
Time complexity:O(N)
Space complexity:O(1)
