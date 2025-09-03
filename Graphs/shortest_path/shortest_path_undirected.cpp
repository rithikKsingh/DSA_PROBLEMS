// link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// tc:O(v+2e) : because undirected
// sc:O(V) for dist array + O(V) for ans

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int>dist(n,INT_MAX);
        vector<int>ans(n,-1);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto a:adj[node]){
               if(dist[a]>1+dist[node]){
                   dist[a]=1+dist[node];
                   q.push(a);
               }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX){
                ans[i]=dist[i];
            }
        }
        return ans;
        
    }
};
