Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix 
as depicted in the following example:

n = 3
mat[][] = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}}
Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
Explaination:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 4,
Move diagonally down to (2, 0): 7,
Move diagonally up to (1, 1): 5,
Move diagonally up to (0, 2): 3,
Move to the right to (1, 2): 6,
Move diagonally up to (2, 1): 8,
Move diagonally up to (2, 2): 9
There for the output is {1, 2, 4, 7, 5, 3, 6, 8, 9}.
Example 2:

Input:
n = 2
mat[][] = {{1, 2},
           {3, 4}}
Output: {1, 2, 3, 4}
Explaination:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 3,
Move to the right to (1, 1): 4
There for the output is {1, 2, 3, 4}.

Code:

class Solution {
public:
    std::vector<int> matrixDiagonally(std::vector<std::vector<int>>& arr) {
        std::map<int, std::vector<int>> m;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                m[i + j].push_back(arr[i][j]);
            }
        }
        
        std::vector<int> v;
        int k = 0;
        for (auto i : m) {
            if (k % 2 == 0 && k > 0) {
                std::reverse(i.second.begin(), i.second.end());
            }
            for (auto ele : i.second) {
                v.push_back(ele);
            }
            k++;
        }
        return v;
    }
};


Time Complexity:
Space Complexity:
