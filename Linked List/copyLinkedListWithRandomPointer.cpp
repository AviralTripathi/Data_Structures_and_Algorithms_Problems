A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.


The problem at hand involves creating a deep copy of a given singly-linked list where each node has a next pointer and an additional random pointer. The random pointer could point to any node within the list or be null. The deep copy should have brand new nodes with the same next and random pointers as the original list.

Key Concepts and Constraints
Node Anatomy:
Each node in the list has an integer value, a next pointer pointing to the subsequent node, and a random pointer that could point to any node in the list or be null.

Deep Copy:
We are required to return a deep copy of the list, meaning that the new list should consist of entirely new nodes that don't refer to nodes in the original list.

Memory Efficiency:
While one approach uses O(n)O(n)O(n) additional memory, the other achieves the task without extra memory, using only O(1)O(1)O(1) extra space.

Strategies to Tackle the Problem
Hash Map Method:
This approach leverages a hash map to store the mapping between each node in the original list and its corresponding node in the copied list.

Interweaving Nodes Method:
This approach cleverly interweaves the nodes of the copied list with the original list, using the structure to adjust the random pointers correctly, and then separates them.


Solution #1: Hash Map Method
Intuition and Logic Behind the Solution
The basic idea is to traverse the list twice. In the first pass, we create a new node for each node in the original list and store the mapping in a hash map. In the second pass, we set the next and random pointers for each new node based on the hash map.

Step-by-step Explanation
Initialization:

Create an empty hash map, old_to_new, to store the mapping from old nodes to new nodes.
First Pass - Node Creation:

Traverse the original list and for each node, create a corresponding new node.
Store the mapping in old_to_new.
Second Pass - Setting Pointers:

Traverse the original list again.
For each node, set its corresponding new node's next and random pointers based on the hash map.

  Code:

  class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return NULL;

        // function to store the mapping of old to new nodes
        unordered_map<Node*,Node*> old_to_new;
        Node* curr=head;
        while(curr)
        {
            old_to_new[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr)
        {
            old_to_new[curr]->next=old_to_new[curr->next];
            old_to_new[curr]->random=old_to_new[curr->random];
            curr=curr->next;
        }
        return old_to_new[head];
    }
};
  
Complexity Analysis
Time Complexity: O(n) — Each node is visited twice.
Space Complexity: O(n) — To store the hash map.
Solution #2: Interweaving Nodes Method
Intuition and Logic Behind the Solution
The crux of this method is to interweave the nodes of the original and copied lists. This interweaving allows us to set the random pointers for the new nodes without needing additional memory for mapping.

Step-by-step Explanation
Initialization and Interweaving:

Traverse the original list.
For each node, create a corresponding new node and place it between the current node and the current node's next.
Setting Random Pointers:

Traverse the interweaved list.
For each old node, set its corresponding new node's random pointer.
Separating Lists:

Traverse the interweaved list again to separate the old and new lists.

  Code:

  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
                if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        Node* old_head = head;
        Node* new_head = head->next;
        Node* curr_old = old_head;
        Node* curr_new = new_head;
        
        while (curr_old) {
            curr_old->next = curr_old->next->next;
            curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        
        return new_head;       
    }
};
  
Complexity Analysis
Time Complexity: O(n) — Each node is visited multiple times but it's still linear time.
Space Complexity: O(1) — No additional memory is used for mapping; we only allocate nodes for the new list.
Both methods provide a deep copy of the original list but differ in their use of additional memory. The choice between them would depend on the specific requirements of your application.
