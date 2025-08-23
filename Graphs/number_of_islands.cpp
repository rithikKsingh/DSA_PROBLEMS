//link :  https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
//TC : O(N*M) + O(N*M*8) ->O(n*m) for each element, and if element is called for the bfs there is addition of 8 directions which are accessed
//SC : O(N*M) + O(N*M) = vis array + queue 
class Solution {
  public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j,int m,int n){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int rows[]={-1,0,1,0,-1,1,1,-1};
        int cols[]={0,1,0,-1,1,1,-1,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int a=0;a<8;a++){
                int nrow=r+rows[a];
                int ncol=c+cols[a];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]==0&&grid[nrow][ncol]=='L'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='L'&&vis[i][j]==0){
                    cnt++;
                    bfs(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
    }
        
};
