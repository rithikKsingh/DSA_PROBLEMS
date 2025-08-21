//link : https://leetcode.com/problems/number-of-enclaves/description/
//tc :O(N*M*4) ~ O(N*M)  , Sc :O(n*M)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+rows[i];
                int ncol=c+cols[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]==1&&vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;              
                    }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
