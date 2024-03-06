Follow the steps below to solve the problem:

Divide the list in two parts – first node and rest of the linked list.
Call reverse for the rest of the linked list.
Link the rest linked list to first.
Fix head pointer to NULL


Time Complexity: O(N), Visiting over every node one time 
Auxiliary Space: O(N), Function call stack space

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
        // in this case simply return the head value
        return head;
        
        Node* rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
    
};



// now there is another way to compute the reverse of a linked list

// iterative way of computation of the reverse of a linkedlist

Follow the steps below to solve the problem:

Initialize three pointers prev as NULL, curr as head, and next as NULL.
Iterate through the linked list. In a loop, do the following:
Before changing the next of curr, store the next node 
next = curr -> next
Now update the next pointer of curr to the prev 
curr -> next = prev 
Update prev as curr and curr as next 
prev = curr 
curr = next



// here is the code for the above implementation

  // rest everything will remain same just like the previous one the only diff will be in the reverse function

  void  reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }


// Time complexity: O(N) just simply traversing over the whole linked list
// Space Complexity: O(1) No extra space has been used
