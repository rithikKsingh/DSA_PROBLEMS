//link : https://www.geeksforgeeks.org/problems/topological-sort/1
// tc: O(E+V) Sc: O(V)

/* 
whats topo sort?
In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

5 -> 0 <- 4
v         v
2 -> 3 -> 1

topo sort :  5 4 0 2 3 1 (there can be multiple answers)

what do you do?
use dfs -> reach the last node -> push it into the stack. As you backtrack, push the current element into stack. Ex in case of 5 0 2 in aboce example, 
you first push 0 and then next element connected with 5 i.e 2 and when all kids are done, you push the parent.

At the end stack contains the elements in sorted order.

NOTE :
its only valid for directed acyclic graph. b/c:
1. if its not directed u - v :  here both u and v should come before each other, but its not possible.
2. acyclic : 0 -> 1 -> 2-> 0 : 0 should come before 1 , 1 should come before 2 and 2 before 0(not possible)
*/
class Solution {
  public:
    void dfs(vector<int>adj[],stack<int>&stk,vector<int>&vis,int node){
        vis[node]=1;
        for(auto a:adj[node]){
            if(vis[a]==0){
                dfs(adj,stk,vis,a);                
            }
        }
        stk.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>vis(V);
        stack<int>stk;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(adj,stk,vis,i);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
