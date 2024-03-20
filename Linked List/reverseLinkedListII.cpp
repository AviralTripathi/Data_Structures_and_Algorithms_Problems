Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from 
position left to position right, and return the reversed list.

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n


  Code: with Explanation as comments

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p=head;
        ListNode* q=NULL;
        int count=1;
        // firstly traverse to the left index
        while(count!=left)
        {
            q=p;
            p=p->next;
            count++;
        }
        ListNode* curr=p->next;
        ListNode* prev=p;
        ListNode* forward=NULL;
        // increment the count variable by one position since we have moved by 1
        // position on setting the curr =p->next since p->next has already 
        // reached us to the left node and now we have proceeded to next node
        // by setting curr=p->next; so eventually increment the count
        // will iterate till the count has reached the right node
        count++;
        while(count<=right)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(q!=NULL)// that simply means that left node was not the first node
        // in the ll
        q->next=prev;
        // the reverse part whose there will obviosuly be head node will be the 
        // head of the new list
        else
        head=prev;
        if(p!=NULL) // please remember p is the node that is the left here
        // so will simply point the left node-next till the node the curr has 
        // traversed
        p->next=curr;
        return head;
    }
};

Complexity Analysis:
