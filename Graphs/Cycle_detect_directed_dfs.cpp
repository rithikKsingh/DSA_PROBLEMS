//link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//tc:O(E+V) +O(V) 
//SC:O(V)+O(V)+O(E+V)+O(V) -> one O(V) each for vis and path, one for recursive stack space. O(E+V) -> for adj list
class Solution {
  public:
    bool dfs(vector<int>adj[],vector<int>&vis,vector<int>&path,int node){
       vis[node]=1;
       path[node]=1;
       for(auto a:adj[node]){
           if(vis[a]==0){
               if(dfs(adj,vis,path,a)){
                   return true;
               }
           }else if(path[a]==1){
               return true;
           }
       }
       path[node]=0;
       return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
   
        vector<int>vis(V);
        vector<int>path(V);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(adj,vis,path,i)){
                    return true;
                }
            }
        }
        return false;
    }
};
