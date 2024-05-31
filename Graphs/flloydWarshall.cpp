Explanation:


Initialization:

The input matrix is a 2D vector representing the adjacency matrix of the graph. If there is no direct edge between two vertices, the corresponding entry is -1.
The algorithm processes the matrix directly to compute the shortest paths.
Main Loop:

The algorithm uses three nested loops to iterate over all pairs of vertices (i, j) and an intermediate vertex k.
The outermost loop iterates over all possible intermediate vertices k.
For each intermediate vertex k, the next two loops iterate over all pairs of vertices (i, j).
The condition if(matrix[i][k] != -1 && matrix[k][j] != -1) ensures that there are paths from i to k and from k to j.
If a path from i to j via k exists, it checks whether this path is shorter than the current known path from i to j. If matrix[i][j] is -1, it means there is no direct path, so it sets the new path length. Otherwise, it updates matrix[i][j] with the minimum path length.




Code:

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    	    int n=matrix.size();
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][k]!=-1&&matrix[k][j]!=-1){
	                    if(matrix[i][j]==-1){
	                        matrix[i][j]=matrix[i][k]+matrix[k][j];
	                    }
	                    else{
	                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                    }
	                }
	                
	            }
	        }
	    }

	}
};


Time Complexity: O(n^3) where n is the number of nodes

Space Complexity: O(n^2) where n is the number of nodes
