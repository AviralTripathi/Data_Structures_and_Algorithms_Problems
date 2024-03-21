In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105

  Approach:

Explanation:

The pairSum function takes a singly linked list head as input and returns an integer representing the maximum sum of pairs of elements taken from the linked list.

Inside the function:

It creates a deque (dq) to store the values of the linked list. A deque is chosen because it supports efficient insertion and deletion from both ends.
It traverses the linked list using a pointer t and pushes the values of each node into the deque.
It initializes the variable ans to the minimum possible integer value (INT_MIN). This variable will store the maximum sum found during the process.
It enters a loop that continues until the deque is not empty:
It calculates the sum (m) of the first and last elements of the deque.
It updates the answer variable (ans) with the maximum of the current sum (m) and the previous maximum.
It removes the first and last elements from the deque to process the next pair of elements.
Finally, it returns the maximum sum obtained.


Code:

class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> dq;
        ListNode* t=head;
        while(t)
        {
            dq.push_back(t->val);
            t=t->next;
        }
        int ans=INT_MIN;

        while(!dq.empty())
        {
            int m=dq.front()+dq.back();
            ans=max(ans,m);
            dq.pop_front();
            dq.pop_back();
        }
        return ans;
    }
};

Complexity Analysis:
