Problem statement:

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
  

Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:

Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:

Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.


  Intuition
The intuition for this problem comes from the idea of BFS, which traverses the graph ("Our case maze"), in a fire spread like fashion i.e., from rings of radius r to r + 1 and so, on.
Now, why does this guarentee us with the optimal solution. We know as the edge node i.e., edge of maze gets added in the queue then, its first occurance will be removed first, which will ensure optimality.

Approach
Let us discuss what tools do we need to solve this problem.
i) A 2D boolean visited array, for avoiding going back to the same cell we came from.
ii) A function which tells us that moving in this direction i.e.,(N , S , E , W) is valid, meaning we are not moving in a wall cell and not moving out of bounds.
iii) Direction vectors dx and dy which save us a lot of if-else conditions (highly recommended to use them).
iv) A variable associated with each cell which tells us the distance of this particular cell from the start.

Now, as we have all the tools.
Let's Begin!!

Get the source position
Initialize the variable - dist (so called distance from source) to 0 (distance of source -> source = 0).
Push this in a queue.
Run a while loop wrto sizeofQueue.
Remove the front element from the queue and store its dist , i and j.
Check whether is it a possible destination, if yes then simply print the dist value.
Add all other possible movable cells and mark them as visited.

  Code:

class Solution {
private:
    bool isValid(vector<vector<char>>& arr, vector<vector<bool>>& vis, int i,
                 int j, int m, int n) {
        return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] &&
                arr[i][j] == '.');
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        int x = entrance[0], y = entrance[1];
        queue<pair<int, pair<int, int>>> q;
        int min_dist = 1e9;

        q.push({0, {x, y}});
        vis[x][y] = true;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int d = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;

            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                !(i == x && j == y) && maze[i][j]=='.') {
                min_dist = d;
                break;
            }

            for (int k = 0; k < 4; k++) {
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                if (isValid(maze, vis, nrow, ncol, m, n)) {
                    vis[nrow][ncol] = true;
                    q.push({d + 1, {nrow, ncol}});
                }
            }
        }

        return (min_dist == 1e9) ? -1 : min_dist;
    }
};

Time Complexity: O(M*N*4)

Space Complexity: O(M*N^2+12)
