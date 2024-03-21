Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Code:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* reverseList(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        // in this case simply return the head value
        return head;
        
        ListNode* rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == NULL)
        return NULL;

    head = reverseList(head);

    ListNode* current = head;
    ListNode* prev = NULL;
    int count = 1;

    while (current != NULL && count < n) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) { // n is greater than the size of the list
        head = reverseList(head); // Re-reverse the list
        return head;
    }

    if (prev == NULL) { // If we are deleting the first node
        ListNode* to_delete = head;
        head = head->next;
        delete to_delete;
    } else {
        prev->next = current->next;
        delete current;
    }

    head = reverseList(head); // Re-reverse the list
    return head;
    }
};
