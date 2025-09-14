// link : https://leetcode.com/problems/shortest-path-in-binary-matrix/

//dfs approach: very bad one
//tc : O(8^(mn)) Sc:O(m*n)
/*
🔹 Time Complexity (TC)
Grid size = m × n.
From each cell, you can move to 8 directions.
Since you backtrack (vis[r][c] = 0 after recursion), you potentially explore all possible paths from (m-1,n-1) to (0,0).
In the worst case (grid full of 0s), every cell can be part of multiple recursive paths.
This leads to exponential exploration:

TC=O(8 ^(m×n))

But do remember many are out of bound paths. so dont need to consider them.
  */
class Solution {
public:
    void find(vector<vector<int>>& grid, vector<vector<int>>& vis, int dist, int r, int c, int& val){
        if(r == 0 && c == 0){
            val = min(val, dist + 1);
            return;
        }

        int row[]={-1,-1,0,-1,0,1,1,1};
        int col[]={0,-1,-1,1,1,1,0,-1};

        vis[r][c] = 1;  // mark visited

        for(int i=0; i<8; i++){
            int nrow = r + row[i];
            int ncol = c + col[i];
            if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() 
               && grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                find(grid, vis, dist + 1, nrow, ncol, val);
            }
        }

        vis[r][c] = 0; // backtrack . in case you visit the same cell again for different paths
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
      
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }

        int val = INT_MAX;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        find(grid, vis, 0, m-1, n-1, val);

        return val == INT_MAX ? -1 : val;
    }
};
