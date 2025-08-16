// Link : https://leetcode.com/problems/flood-fill/description/
//TC:O(M*N) SC:O(M*N)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int startCol=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+rows[i];
                int ncol=c+cols[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]==0&&image[nrow][ncol]==startCol){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};
