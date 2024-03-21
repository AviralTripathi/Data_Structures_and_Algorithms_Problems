Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109


Code:

class Solution {
public:
    void solve(ListNode*& head, int k) {
        if (head == NULL || k == 0)
            return;

        int length = 1;
        ListNode* tail = head;

        // Find the length of the list and locate the tail
        while (tail->next != NULL) {
            length++;
            tail = tail->next;
        }

        // Adjust k if it's larger than the length of the list
        k = k % length;
        if (k == 0)
            return;

        // Find the new tail (the node just before the new head after rotation)
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // Make the list circular
        tail->next = head;

        // Update the head and break the link at the new tail
        head = new_tail->next;
        new_tail->next = NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        solve(head, k);
        return head;
    }
};

Complexity Analysis:
