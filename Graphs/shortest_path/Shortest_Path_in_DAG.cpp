//link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// tc: O(E+V), sc:O(E+V) -> for adj list +  O(V) -> dist array 


class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        int src=0;
        for(int i=0;i<E;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>dist(V,INT_MAX);
        vector<int>ans(V,-1);
        
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto a:adj[node]){
                if((dist[node]+a.second)<dist[a.first]){
                    dist[a.first]=dist[node]+a.second;
                    q.push(a.first);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]!=INT_MAX){
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};
