//link : https://leetcode.com/problems/path-with-minimum-effort/

/*
  Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent 
nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue } 


as we want to find the minimum diff, we use priority queue
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1&&c==m-1) return diff;

            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];

                if(nr<n&&nr>=0&&nc<m&&nc>=0){
                    int newDiff=max(diff,abs(heights[nr][nc]-heights[r][c]));
                    if(dist[nr][nc]>newDiff){
                     dist[nr][nc]= newDiff;
                     pq.push({newDiff,{nr,nc}});  
                    }
                }
            }
        }
        return 0;
    }
};
