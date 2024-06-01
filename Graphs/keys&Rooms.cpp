There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.


Code:

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        // declaring a vector visited of the size = no.of rooms  and initializing 
        // all of them
        // to false
        vector<bool> v(rooms.size(),false);
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            // mark the particular room as being visited and unlocked
            v[p]=true;
            // iterate over the neighbors here the neighbors are the rooms 
            // whoose keys are found in that particular room that has been unlocked
            for(auto it:rooms[p])
            {
                // checking for the case if the room has been already unlocked or not
                if(!v[it])
                // then push the room node inside the queue
                q.push(it);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(!v[i])
            // if there is any room which is still unvisited and unlocked
            // then return false;
            return false;
        }
        // this means that all the rooms have been visited and unlocked as well
        return true;
    }
};


Time Compexity: O(V+E) which can be O(V^2) in the worst case

Space Complexity: O(V)
