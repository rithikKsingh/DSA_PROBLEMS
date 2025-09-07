// link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// TC: O(E+V) SC:O(V)

/*
approach:

do toposort -> then travese through the stack. check if ParentNodeDist+WeightOfCurrent < DistOfCurr. if yes, then edit the distance. 
Also do check if ParentNodeDist is not Max.
  */
class Solution {
  public:
    void toposort(vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&stk,int node){
        vis[node]=1;
        for(auto a:adj[node]){
            if(vis[a.first]!=1){
                toposort(adj,vis,stk,a.first);
            }
        }
        stk.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        vector<int>vis(V);
        vector<int>dist(V,INT_MAX);
        vector<int>ans(V,-1);
        int src=0;
        for(int i=0;i<E;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int>stk;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(adj,vis,stk,i);
            }
        }
        dist[src]=0;
        while(!stk.empty()){
            int node=stk.top();
            stk.pop();
            for(auto a:adj[node]){
                if(dist[node]!=INT_MAX && dist[node]+a.second<dist[a.first]){
                    dist[a.first]=dist[node]+a.second;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
