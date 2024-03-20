Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer

 and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Code with proper expnation

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int count = 0;

    // Count the number of nodes in the current group
    ListNode* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // If the number of nodes in the current group is less than k, return head as it is
    if (count < k) {
        return head;
    }

    // Reverse the current group
    count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse the next group and attach it to the end of the current reversed group
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // Return the new head of the reversed group
    return prev;
    }
};

Complexity Analysis:

