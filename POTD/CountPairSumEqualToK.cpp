Given two linked list head1 and head2 with distinct elements, determine the count of all distinct pairs from both lists whose sum is equal to the given value x.

Note: A valid pair would be in the form (x, y) where x is from first linked list and y is from second linked list.

Example 1:

Input:
head1 = 1->2->3->4->5->6
head2 = 11->12->13
x = 15
Output: 3
Explanation: There are total 3 pairs whose sum is 15 : (4,11) , (3,12) and (2,13)
Example 2:

Input:
head1 = 7->5->1->3
head2 = 3->5->2->8
x = 10
Output: 2
Explanation: There are total 2 pairs whose sum is 10 : (7,3) and (5,5)

Code:

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int>s;
        Node*temp=head1;
        while(temp){
            s.insert(temp->data);
            temp=temp->next;
        }
        temp=head2;
        int c=0;
        while(temp){
            int t=temp->data;
            if(s.find(x-t)!=s.end()){
                c++;
            }
            temp=temp->next;
        }
        return c;
    }
};

Time Complexity:
Space Complexity:
