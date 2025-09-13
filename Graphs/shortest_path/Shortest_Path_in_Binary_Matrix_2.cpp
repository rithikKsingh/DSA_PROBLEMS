// link : https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/1768883464/
// tc: o(8*m*n) sc:O(m*n)

/*
aproach : using dijextra (queue)

why have we used queue:
Why queue?
Queue = FIFO (First In First Out)
First, you push the source (dist = 0).
Its neighbors get pushed after it (dist = 1).
Then neighbors of those (dist = 2)… and so on.
So you’re always expanding the nearest layer before moving on.
Stack/DFS explores depth first → it can go deep into a path without knowing whether it’s the shortest. You’d need to backtrack and compare all paths, which becomes exponential.
Queue guarantees shortest distance naturally.

the distances are increasing monotonically (because of constant edge weights). Since greater distance comes at the top automatically, 
so we do not need the priority queue as the pop operation will always pop the smaller distance which is at the front of the queue. 
This helps us to eliminate an additional log(N) of time needed to perform insertion-deletion operations in a priority queue.

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==1||grid[m-1][n-1]==1) return -1;

        if(m==1&&n==1) return 1;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        queue<pair<int,pair<int,int>>>q;

        dist[0][0]=1;
        q.push({1,{0,0}}); // generally source have 0 distance, but in question source is considered at a dist of 1 from itself.

        int row[]={0,1,1,1,0,-1,-1,-1};
        int col[]={1,1,0,-1,-1,-1,0,1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]==0&&dis+1<dist[nrow][ncol]){
                   dist[nrow][ncol]=1+dis;
                   if(nrow==m-1&&ncol==n-1) return dis+1;
                   q.push({1+dis,{nrow,ncol}}); 
                }
            }
        }
        return -1;
    }
};
