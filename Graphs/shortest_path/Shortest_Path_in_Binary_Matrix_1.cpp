// link : https://leetcode.com/problems/shortest-path-in-binary-matrix/

//dfs approach: very bad one
//tc : O(2^(mn)) Sc:O(m*n)
/*
🔹 Step 1: Grid has m * n cells
Suppose the grid has k = m*n free cells (0s).
🔹 Step 2: DFS explores all possible paths
From each cell, DFS can either include that cell in the current path or not include it (because of backtracking, you may revisit it through another branch).
That means for each cell, there are ~2 choices.
🔹 Step 3: Total possible combinations
If each of the k cells can be in/out of a path, the total number of possible paths explored is about:
2k=2(m⋅n)
 
🔹 Example
Take a 2×2 grid (4 cells, all zero):
DFS could generate up to 2^4 = 16 different possible cell-visit combinations.
For a 3×3 grid (9 cells):
Up to 2^9 = 512 paths.
And it explodes very fast for larger grids.
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
