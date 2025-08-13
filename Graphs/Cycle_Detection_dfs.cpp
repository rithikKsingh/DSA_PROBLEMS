//link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
//tcs: O(V+2E) //SC:O(V)+O(V) one for vis array and other for recursive stack space
class Solution {
  public:
    bool dfs(vector<int>adj[],int source,int par,vector<int>&vis){
      vis[source]=1;
      for(auto a:adj[source]){
          if(!vis[a]){
              if(dfs(adj,a,source,vis)){
                  return true;
              }
          }else if(par!=a){
              return true;
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
                if(dfs(adj,i,-1,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
