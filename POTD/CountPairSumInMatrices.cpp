Given two sorted matrices mat1 and mat2 of size n x n of elements. Each matrix contains numbers arranged in strictly ascending order, with each row sorted from left to right, and the last element of a row being smaller than the first element of the next row. You're given a target value, x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where sum of a and b is equal to x.

Example 1:

Input: 
n = 3, x = 21
mat1 = {{1, 5, 6},
        {8, 10, 11},
        {15, 16, 18}}
mat2 = {{2, 4, 7},
        {9, 10, 12},
        {13, 16, 20}}
OUTPUT: 4
Explanation: The pairs whose sum is found to be 21 are (1, 20), (5, 16), (8, 13), (11, 10).
Example 2:

Input:
n = 2, x = 10
mat1 = {{1, 2},
        {3, 4}}
mat2 = {{4, 5},
        {6, 7}}
Output: 2
Explanation: The pairs whose sum found to be 10 are (4, 6), (3, 7)

Algo:

From the top leftmost element traverse mat1[][] in forward direction (i.e., from the topmost row up to last, each row is being traversed 
from left to right) and from the bottom rightmost element traverse mat2[][] in backward direction (i.e, from the bottom row up to first, 
  each row is being traversed from right to left). For each element e1 of mat1[][] and e2 of mat2[][] encountered, calculate val = (e1 + e2). 
If val == x, increment count. Else if val is less than x, move to next element of mat1[][] in forward direction. 
Else move to next element of mat2[][] in backward direction. Continue this process until either of the two matrices gets completely traversed.

Code:

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	       // 'r1' and 'c1' for pointing current element
    // of mat1[][]
    // 'r2' and 'c2' for pointing current element
    // of mat2[][]
    int r1 = 0, c1 = 0;
    int r2 = n - 1, c2 = n - 1;
 
    // while there are more elements
    // in both the matrices
    int count = 0;
    while ((r1 < n) && (r2 >= 0)) {
        int val = mat1[r1][c1] + mat2[r2][c2];
 
        // if true
        if (val == x) {
 
            // increment 'count'
            count++;
 
            // move mat1[][] column 'c1' to right
            // move mat2[][] column 'c2' to left
            c1++;
            c2--;
        }
 
        // if true, move mat1[][] column 'c1' to right
        else if (val < x)
            c1++;
 
        // else move mat2[][] column 'c2' to left
        else
            c2--;
 
        // if 'c1' crosses right boundary
        if (c1 == n) {
 
            // reset 'c1'
            c1 = 0;
 
            // increment row 'r1'
            r1++;
        }
 
        // if 'c2' crosses left boundary
        if (c2 == -1) {
 
            // reset 'c2'
            c2 = n - 1;
 
            // decrement row 'r2'
            r2--;
        }
    }
 
    // required count of pairs
    return count;
        
	}

Time Complexity: O(n^2)
Space Complexity:  O(1) // we have not used any extra space
