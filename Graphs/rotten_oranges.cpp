//tc:O(n2)*4 (i worst case when all rotten oranges are presnt, we would have to check each of the 4 direction)
//sc:O(n2)
//link : https://leetcode.com/problems/rotting-oranges/description/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        
        int cnt=0;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            cnt=max(cnt,t);

            for(int i=0;i<4;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow<m&&nrow>=0&&ncol<n&&ncol>=0&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    cout<<i<<" "<<j<<endl;
                    return -1;
                }
            }
        }
        return cnt;
    }
};
