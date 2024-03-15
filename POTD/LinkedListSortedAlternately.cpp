You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

Example 1:

Input:
n = 6
LinkedList = 1->9->2->8->3->7
Output: 1 2 3 7 8 9
Explanation: 
After sorting the given list will be 1->2->3->7->8->9.
Example 2:

Input:
n = 5
LinkedList = 13->99->21->80->50
Output: 13 21 50 80 99
Explanation:
After sorting the given list will be 13->21->50->80->99.

Code:

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
                  // Code here
         Node *head1=new Node(0),*head2=new Node(0);
         Node *temp1=head1,*temp2=head2,*temp=*head;
         bool indication=true;
         while(temp){
             if(indication){
                 temp1->next=temp;
                 temp1=temp1->next;
             }
             else{
                 temp2->next=temp;
                 temp2=temp2->next;
             }
             temp=temp->next;
             indication=!indication;
         }
         temp1->next=NULL;
         temp2->next=NULL;
         Node *curr=head2,*prev=NULL,*nxt=head2->next;
         while(curr){
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
         }
         temp=prev;
         while(prev){
             if(prev->next==head2){
                 prev->next=NULL;
             }
             prev=prev->next;
         }
         Node *ans = new Node(0);
         head2=ans;
         head1=head1->next;
         while(head1 and temp){
             if(head1->data<=temp->data){
                 ans->next=head1;
                 head1=head1->next;
             }
             else{
                 ans->next=temp;
                 temp=temp->next;
             }
             ans=ans->next;
         }
         while(head1){
             ans->next=head1;
             head1=head1->next;
             ans=ans->next;
         }
         while(temp){
             ans->next=temp;
             temp=temp->next;
             ans=ans->next;
         }
         *head=head2->next;
    }
};
