//link: https://leetcode.com/problems/01-matrix/
//TC:O(M*N) SC: O(N*M) +O(N*M)+O(N*M) = O(N*M)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+rows[i];
                int ncol=c+cols[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]==0&&mat[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=t+1;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        return ans;
    }
};
