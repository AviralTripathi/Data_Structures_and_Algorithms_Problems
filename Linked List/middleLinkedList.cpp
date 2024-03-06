Traverse linked list using two-pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end, the slow pointer will reach the middle of the linked list.

  Time Complexity: O(N), As we are traversing the list only once.
Auxiliary Space: O(1), As constant extra space is used.

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* fast=head;
        Node* slow=head;
        
        if(head!=NULL)
        {
            while(fast!=NULL && fast->next!=NULL)
            {
                fast=fast->next->next;
                slow=slow->next;
            }
            return slow->data;
        }
        
    }
};
