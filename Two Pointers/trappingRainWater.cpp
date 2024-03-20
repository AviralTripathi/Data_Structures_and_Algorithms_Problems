Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105



Intuition
The problem requires calculating the amount of water that can be trapped between the buildings. To trap water effectively, we need to find
the maximum height of buildings to the left and right of each building. By doing this, we can determine the height of the water at each building position. 
Then, the trapped water for each building is calculated by subtracting the height of the building itself from the minimum of the maximum heights from the 
left and right sides.

Approach
-> Initialize arrays to store the maximum height to the left and right of each building.
-> Iterate through the height array to populate these arrays.
-> Calculate the minimum of the maximum heights from the left and right for each building and store them in another array.
-> Iterate through the height array again to calculate the trapped water by subtracting the height of each building from the corresponding minimum height.
-> Accumulate the trapped water and return the result.

  Code:

  class Solution {
public:
    int trap(vector<int>& height) {
        // computing the size of the height vector
        int n = height.size();
        // declaring a vector to compute the maximum height to the right of the
        // every building
        vector<int> rheight(n);
        rheight[n - 1] = height[n - 1];
        for (int i = n - 2; i >=0; i--)
            rheight[i] = max(rheight[i + 1], height[i]);
        // vector array to store the maximum lenghth to the left of each
        // building
        vector<int> lheight(n);
        lheight[0] = height[0];
        for(int i=1;i<n;i++)
        lheight[i] = max(lheight[i - 1], height[i]);
        // arrays to store the minimum of the maximum and minimum height of the
        // each building
        vector<int> minHeight(n);
        for (int i = 0; i < n; i++)
            minHeight[i] = min(lheight[i], rheight[i]);
        // calculate the water trapped by subtrating height of each building by
        // subtracting height of each building
        int trappedWater = 0;
        for (int i = 0; i < n; i++)
            trappedWater += (minHeight[i] - height[i]);
        // finally return the answer
        return trappedWater;
    }
};
  
Complexity

  -> Time complexity: O(n)O(n)O(n) - We iterate through the height array three times, each with O(n)O(n)O(n) complexity.
-> Space complexity: O(n)O(n)O(n) - We use additional space to store the maximum heights to the left and right of each building, as well as the minimum of those heights.
