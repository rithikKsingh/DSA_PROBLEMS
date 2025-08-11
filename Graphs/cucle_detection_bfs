//tc: O(V+2E), 2E is for total degrees as we traverse all adjacent nodes
//sc:O(n)
class Solution {
  public:
    bool bfs(vector<int>adj[],int source,vector<int>&vis){
        queue<pair<int,int>>q;
        vis[source]=1;
        q.push({source,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto a:adj[node]){
                if(!vis[a]){
                    vis[a]=1;
                    q.push({a,node});
                }else if(parent!=a){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        
        vector<int>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(adj,i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
