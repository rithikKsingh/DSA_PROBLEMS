// link : https://leetcode.com/problems/surrounded-regions/description/

//TC:O(N*M) SC:O(N*M)

//you need to mark all the connected "O" cells which are connected with edges (indorectly or directly) as visited. The ones left are marked "X".

//using bfs 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if((i==0||i==m-1||j==0||j==n-1)&&(board[i][j]=='O')){
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

                if(nrow>0&&nrow<m&&ncol>0&&ncol<n&&board[nrow][ncol]=='O'&&vis[nrow][ncol]!=1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};


// using dfs
class Solution {
    private: void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int row,int col,int drow[],int dcol[]){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&
            board[nrow][ncol]=='O'){
                dfs(board,vis,nrow,ncol,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&board[0][j]=='O'){
                dfs(board,vis,0,j,drow,dcol);
            }
            if(!vis[n-1][j]&&board[n-1][j]=='O'){
                dfs(board,vis,n-1,j,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i][0]==0&&board[i][0]=='O'){
                dfs(board,vis,i,0,drow,dcol);
            }

            if(vis[i][m-1]==0&&board[i][m-1]=='O'){
                dfs(board,vis,i,m-1,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0)
                board[i][j]='X';
            }
        }
    }
};
