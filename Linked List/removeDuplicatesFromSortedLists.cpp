Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.
 
Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.


Code:

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current=head;
        vector<int> values;
        unordered_map<int,int> freq;
        vector<int> ans;
        while(current!=NULL)
        {
            values.push_back(current->val);
            current=current->next;
        }
        for(int num:values)
        freq[num]++;
        for(auto it:freq)
        {
            if(it.second==1)
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        // further we have followed the dummy node approach
        ListNode* res=new ListNode(0);
        ListNode* newcurr=res;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* node=new ListNode(ans[i]);
            newcurr->next=node;
            newcurr=newcurr->next;
        }
        return res->next;

    }
};

Complexity Analysis:
